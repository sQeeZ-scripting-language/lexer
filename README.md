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