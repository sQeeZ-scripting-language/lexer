#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class TokenType {
    TOKEN_EOF,
    // Keywords
    TOKEN_IF,
    TOKEN_ELSE,
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
