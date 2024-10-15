# sQeeZ Lexer
The **sQeeZ Lexer** is designed to break down the source code of the sQeeZ scripting language into tokens, which are the fundamental building blocks used by the parser and interpreter. This lexer adheres to the core principles of sQeeZ: compactness, readability by convention, and a focus on data structures.

# Table of Contents
- [How to Use](#how-to-use)
  - [Install Dependencies](#install-dependencies)
  - [Build & Run](#build--run)
  - [Node Module](#node-module)
  - [Testing](#testing)
  - [Code Formatting](#code-formatting)
- [Tokens](#tokens)
  - [Token Structure](#token-structure)
  - [Basic Tokens](#basic-tokens)
  - [Syntax Tokens](#syntax-tokens)
  - [Keyword Tokens](#keyword-tokens)
  - [Operator Tokens](#operator-tokens)
  - [Logical Tokens](#logical-tokens)
  - [Log Tokens](#log-tokens)
  - [Data Tokens](#data-tokens)

# How to Use
> **Note:**
> 
> For convenience, each category (Dependencies, Build, Node-Build, Testing, Code Formatting) has a corresponding script:
> 
> - `dependencies.sh`
> - `build.sh`
> - `node.sh`
> - `test.sh`
> - `checkstyle.sh`
> 
> These scripts can be run directly from the root directory of the project to automate the respective tasks.

## Install Dependencies

### 1. Install Node Dependecies
```bash
npm install
```

## Build & Run
To compile the project, follow these steps:

### 1. Create and Navigate to Build Directory
```bash
mkdir build
cd build
```

### 2. Configure the Project with CMake
```bash
cmake ..
```

### 3. Build the Project
```bash
cmake --build .
```

### 4. Run the generated Executable
```bash
cd build
./sQeeZ-Lexer-Exe $FILE_PATH.sqz [--dev]
```

## Node Module
To compile the Lexer API as a Node Module, do the following:

### 1. Compile the Node Module
```bash
cmake-js compile --CDNODE=true
```

### 2. Import the Node Module into a JS-File
```javascript
const addon = require('./build/Release/sQeeZ-Lexer-Node');
const lexer = new addon.LexerNode(require);
```

> An example of how to use this library can be found in the [`index.js`](./index.js) file.

## Testing
To run the tests, do the following:

### 1. Navigate to the Build Directory
```bash
cd build
```

### 2. Execute the Tests
```bash
./lexer_test
```
or
```bash
ctest --output-on-failure
```

## Code Formatting
To format your code, execute the following script, which will apply the clang-format to all .cpp and .hpp files in the project directory:

### 1. Apply clang-format
```bash
function format_file {
  local file=$1
  clang-format -i "$file"
}

for file in $(find . -name '*.cpp' -o -name '*.hpp'); do
  format_file "$file"
done
```

# Tokens
The lexer identifies several token types that reflect the compact nature of the sQeeZ language. Each token is categorized based on its role in the language, and is structured using the Token class. This class provides a flexible and efficient way to represent various tokens using an enum and a union for different token types.

## Token Structure
```cpp
struct Token {
  enum class TypeTag { BASIC, DATA, KEYWORD, LOG, LOGICAL, OPERATOR, SYNTAX } tag;

  union TokenType {
    BasicToken basicToken;
    DataToken dataToken;
    KeywordToken keywordToken;
    LogToken logToken;
    LogicalToken logicalToken;
    OperatorToken operatorToken;
    SyntaxToken syntaxToken;

    TokenType() {}
    TokenType(BasicToken t) : basicToken(t) {}
    TokenType(DataToken t) : dataToken(t) {}
    TokenType(KeywordToken t) : keywordToken(t) {}
    TokenType(LogToken t) : logToken(t) {}
    TokenType(LogicalToken t) : logicalToken(t) {}
    TokenType(OperatorToken t) : operatorToken(t) {}
    TokenType(SyntaxToken t) : syntaxToken(t) {}
  } type;

  int size;
  std::string value;
  std::string plainText;
  std::string desc;

  Token(BasicToken token, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::BASIC),
        type(token),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(DataToken token, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::DATA),
        type(token),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(KeywordToken token, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::KEYWORD),
        type(token),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(LogToken token, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::LOG),
        type(token),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(LogicalToken token, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::LOGICAL),
        type(token),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(OperatorToken token, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::OPERATOR),
        type(token),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(SyntaxToken token, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::SYNTAX),
        type(token),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}

  std::string toString(int pos) const;
  std::string getTagString() const;
  std::string getTypeString() const;
};
```

## Basic Tokens
This enum provides a base for handling fundamental lexical states, ensuring that the lexer properly tracks the beginning, end, and any unrecognized tokens encountered during tokenization.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `INIT` | 0 | \0 | Represents the initial state before any token has been identified. |
| `TOKEN_EOF` | 0 | \0 | Indicates the end of the input stream (end-of-file). |
| `UNKNOWN` | 1 | The Next Charackter | Marks the next charackter as a token that the lexer cannot categorize. |

## Syntax Tokens
This enum class categorizes various syntax tokens used in the sQeeZ language. These tokens represent punctuation and structural elements that define the organization of the code, such as grouping expressions, separating statements, and denoting specific syntax patterns.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `SEMICOLON` | 1| ; | The Semicolon, used to terminate statements |
| `COMMA` | 1| , | The Comma, used to separate elements in lists or parameters |
| `DOT` | 1| . | The Dot, typically, used for accessing members or methods |
| `COLON` | 1 | : | The colon, used in various syntax constructs like slice operations |
| `SINGLE_QUOTE` | 1 | ' | The Single Quote, used for character or string literals |
| `DOUBLE_QUOTE` | 1 | " | The Double Quote, used for string literals |
| `OPEN_PARENTHESIS` | 1 | ( | The Opening Parenthesis, used for grouping expressions or function calls |
| `CLOSE_PARENTHESIS` | 1 | ) | The Closing Parenthesis, used for grouping expressions or function calls |
| `OPEN_BRACKET` | 1 | [ | The Opening Bracket, used for array or list indexing |
| `CLOSE_BRACKET` | 1 | ] | The Closing Bracket, used for array or list indexing |
| `OPEN_BRACE` | 1 | { | The Opening brace, used to define blocks of code or object literals |
| `CLOSE_BRACE` | 1 | } | The Closing brace, used to define blocks of code or object literals |
| `INLINE_COMMENT` | 2 | // | The Inline Comment, used for single-line comments in the code |
| `PIPE` | 1 | \| | Pipe |
| `PIPE_OPERATOR` | 2 | \|> | Pipe Operator |
| `ARROW` | 2 | ->| The Arrow Operator, used in lambda expressions |
| `HASHTAG` | 1 | # | The Hashtag, used for Hex-Codes |
| `AT` | 1 | @ | AT |

## Keyword Tokens
This enum class categorizes the reserved keywords used in the sQeeZ language. These keywords are integral to the language’s syntax and control flow, defining key constructs such as variable declarations, conditional statements, loops, and function definitions. By identifying these tokens, the lexer can correctly parse and interpret language constructs, ensuring that the code adheres to the language's syntax rules and functionality.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `VARIABLE` | 3 | var | Keyword for declaring a Variable |
| `CONSTANT` | 5 | const | Keyword for declaring a Constant |
| `IF` | 2 | if | Keyword for initiating a Conditional Statement |
| `ELSE` | 4 | else | Keyword for specifying an Alternative Branch in a Conditional Statement |
| `ELSE_IF` | 4 | elif | Keyword for adding Additional Conditions to an Conditional Statement |
| `FOR` | 3 | for | Keyword for starting a Loop |
| `WHILE` | 5 | while | While loop |
| `DO` | 2 | do | Do While loop |
| `FUNCTION` | 2 | fn | Keyword for defining a Function |
| `RETURN` | 6 | return | Keyword for Returning a Value from a Function |
| `IN` | 2 | in | In keyword |
| `OF` | 2 | of | Of keyword |

## Operator Tokens
This enum class categorizes various operators used in the sQeeZ language for mathematical operations and assignments. These tokens represent both basic arithmetic operations and their compound assignment counterparts, along with special operators like increment, decrement and potentation.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `ASSIGN` | 1 | = | Assignment operator |
| `ADDITION` | 1 | + | Addition operator |
| `SUBTRACTION` | 1 | - | Subtraction operator |
| `MULTIPLICATION` | 1 | * | Multiplication operator |
| `DIVISION` | 1 | / | Division operator |
| `MODULUS` | 1 | % | Modulus operator |
| `ADDITION_ASSIGNMENT` | 2 | += | Addition Assignment operator (Adds and Assigns) |
| `SUBTRACTION_ASSIGNMENT` | 2 | -= | Subtraction Assignment operator (Subtracts and Assigns) |
| `MULTIPLICATION_ASSIGNMENT` | 2 | *= | Multiplication Assignment operator (Multiplies and Assigns) |
| `DIVISION_ASSIGNMENT` | 2 | /= | Division Assignment operator (Divides and Assigns) |
| `MODULUS_ASSIGNMENT` | 2 | %= | Modulus Assignment operator (Modulus and Assigns) |
| `INCREMENT` | 2 | ++ | Increment operator (Increases value by 1) |
| `DECREMENT` | 2 | -- | Decrement operator (Decreases value by 1) |
| `POTENTIATION` | 2 | ** | Potentiation operator (Exponentiation) |

## Logical Tokens
This enum class categorizes logical operators used in conditional expressions within the sQeeZ language. These tokens facilitate the creation of complex logical conditions by providing various operators for equality checks, comparisons, and logical operations.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `EQUAL` | 2 | == | Compare two values for Equality |
| `NOT_EQUAL` | 2 | != | Compare two values for Non-Equality |
| `GREATER` | 1 | > | Compare if one value is Larger than another |
| `LESS` | 1 | < | Compare if one value is Smaller than another |
| `GREATER_EQUAL` | 2 | >= | Compare if one value is Greater Than or Equal to another |
| `LESS_EQUAL` | 2 | <= | Compare if one value is Smaller Than or Equal to another |
| `AND` | 2 | && | The logical AND used to combine two boolean expressions |
| `OR` | 2 | \|\| | The logical OR used to combine two boolean expressions |
| `NOT` | 1 | ! | The logical NOT used to negate a boolean expression |

## Log Tokens
This enum class categorizes various types of log tokens used in the sQeeZ language for output and debugging purposes. These tokens enable different logging behaviors, including the basic output, a colored formatting for better visibility, and specific log levels such as warnings and errors.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `BASIC` | 3 | log | Basic Log Output without any special formatting |
| `COLORED` | 4 | logc | Log Output with Color Formatting for better visibility |
| `WARN` | 4 | warn | Warning Log Output indicating a Potential Issue |
| `ERROR` | 5 | error | Error Log Output indicating a Critical Issue that needs attention |

## Data Tokens
This enum class categorizes various types of data tokens used in the sQeeZ language. These tokens represent different literal types and identifiers, enabling the recognition and handling of various data structures within the language.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `COMMENT_LITERAL` | Length of the Comment Literal | The Comment Literal | Represents a Comment Literal |
| `STRING_LITERAL` | Length of the String Literal | The String Literal | Represents a String Literal |
| `INTEGER_LITERAL` | Length of the Integer Literal | The Integer literal | Represents an Integer Literal |
| `DOUBLE_LITERAL` | Length of the Double Literal | The Double literal | Represents a Double Literal |
| `IDENTIFIER` | Size of the Identifier | The Identifier | Marks an Identifier |

[Back to Top](#sqeez-lexer)