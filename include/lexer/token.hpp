#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class TokenType {
    TOKEN_EOF,
    // Keywords
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_ELSE_IF,
    TOKEN_FOR,
    TOKEN_IN,
    TOKEN_BREAK,
    TOKEN_CONTINUE,
    TOKEN_RETURN,
    TOKEN_FUNCTION,
    TOKEN_LET,
    TOKEN_CONST,
    // Log
    TOKEN_LOG_COLORED,
    TOKEN_LOG_BASIC,
    TOKEN_LOG_ERROR,
    // Unknown
    TOKEN_UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

#endif
