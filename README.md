# sQeeZ Lexer

The **sQeeZ Lexer** is designed to break down the source code of the sQeeZ scripting language into tokens, which are the fundamental building blocks used by the parser and interpreter. This lexer adheres to the core principles of sQeeZ: compactness, readability by convention, and a focus on data structures.

## Token Types
The lexer identifies several token types that reflect the compact nature of the sQeeZ language. Each token is categorized based on its role in the language, and is structured using the Token class. This class provides a flexible and efficient way to represent various tokens using an enum and a union for different token types.

```cpp
struct Token {
    enum class TypeTag { BASIC, DATA, ERROR, KEYWORD, LOG, LOGICAL, OPERATOR, SYNTAX } tag;

    union TokenType {
        BasicToken basicToken;
        DataToken dataToken;
        ErrorToken errorToken;
        KeywordToken keywordToken;
        LogToken logToken;
        LogicalToken logicalToken;
        OperatorToken operatorToken;
        SyntaxToken syntaxToken;

        TokenType() {}
        TokenType(BasicToken t) : basicToken(t) {}
        TokenType(DataToken t) : dataToken(t) {}
        TokenType(ErrorToken t) : errorToken(t) {}
        TokenType(KeywordToken t) : keywordToken(t) {}
        TokenType(LogToken t) : logToken(t) {}
        TokenType(LogicalToken t) : logicalToken(t) {}
        TokenType(OperatorToken t) : operatorToken(t) {}
        TokenType(SyntaxToken t) : syntaxToken(t) {}
    } type;

    int size;
    std::string value;
    std::string desc;

    Token(BasicToken b, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::BASIC), type(b), size(size), value(std::move(value)), desc(std::move(desc)) {}

    Token(DataToken d, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::DATA), type(d), size(size), value(std::move(value)), desc(std::move(desc)) {}

    Token(ErrorToken e, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::ERROR), type(e), size(size), value(std::move(value)), desc(std::move(desc)) {}

    Token(KeywordToken k, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::KEYWORD), type(k), size(size), value(std::move(value)), desc(std::move(desc)) {}

    Token(LogToken l, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::LOG), type(l), size(size), value(std::move(value)), desc(std::move(desc)) {}

    Token(LogicalToken l, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::LOGICAL), type(l), size(size), value(std::move(value)), desc(std::move(desc)) {}

    Token(OperatorToken o, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::OPERATOR), type(o), size(size), value(std::move(value)), desc(std::move(desc)) {}

    Token(SyntaxToken s, int size = 0, std::string value = "", std::string desc = "")
        : tag(TypeTag::SYNTAX), type(s), size(size), value(std::move(value)), desc(std::move(desc)) {}
};
```

### Basic Tokens
This enum provides a base for handling fundamental lexical states, ensuring that the lexer properly tracks the beginning, end, and any unrecognized tokens encountered during tokenization.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `INIT` | 0 | \0 | Represents the initial state before any token has been identified. |
| `TOKEN_EOF` | 0 | \0 | Indicates the end of the input stream (end-of-file). |
| `UNKNOWN` | 1 | The Next Charackter | Marks the next charackter as a token that the lexer cannot categorize. |

### Data Tokens
This enum class categorizes identifiers and values used in data-related operations, allowing the lexer to handle both definitions and usages of variables, constants, and functions, as well as different literal types.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `SET_FUNCTION_IDENTIFIER` | Size of the Function Identifier | The Function Identifier | Defines a Function Identifier |
| `SET_VARIABLE_IDENTIFIER` | Size of the Variable Identifier | The Variable Identifier | Defines a Variable Identifier |
| `SET_CONSTANT_IDENTIFIER` | Size of the Constant Identifier | The Constant Identifier | Defines a Constant Identifier |
| `USE_FUNCTION_IDENTIFIER` | Size of the Function Identifier | The Function Identifier | Refers to a previously defined Function |
| `USE_VARIABLE_IDENTIFIER` | Size of the Variable Identifier | The Variable Identifier | Refers to a previously defined Variable |
| `USE_CONSTANT_IDENTIFIER` | Size of the Constant Identifier | The Constant Identifier | Refers to a previously defined Constant |
| `STRING_LITERAL` | Length of the String Literal | The String Literal | Represents a String Literal |
| `INTEGER_LITERAL` | Length of the Integer Literal | The Integer literal | Represents an Integer Literal |
| `DOUBLE_LITERAL` | Length of the Double Literal | The Double literal | Represents a Double Literal |

### Error Tokens
This enum class categorizes various error conditions encountered by the lexer during tokenization. These tokens help diagnose problems such as undefined identifiers, reserved keyword misuse, and format issues. Each error token pinpoints the exact nature of the problem, facilitating easier debugging and code correction.

| **Token** | **Size** | **Value** | **Description** |
| --- | --- | --- | --- |
| `IDENTIFIER_NOT_FOUND` | Size of the Identifier | The Identifier | Raised when an Identifier is used before Definition |
| `IDENTIFIER_RESERVED_KEYWORD` | Size of the Identifier | The Identifier | Raised when an Identifier is a Reserved Keyword|
| `IDENTIFIER_ALREADY_EXISTS` | Size of the Identifier | The Identifier | Raised when attempting to define an Identifier that already exists |
| `IDENTIFIER_INVALID_FORMAT` | Size of the Identifier | The Identifier | Raised when an Identifier does not meet the required Naming Conventions |
| `IDENTIFIER_INVALID_TYPE` | Size of the Identifier | The Identifier | Raised when an Identifier is used with an unexpected Type |
