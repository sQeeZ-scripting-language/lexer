#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class TokenType {
    TOKEN_EOF,
    TOKEN_LOG,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

#endif
