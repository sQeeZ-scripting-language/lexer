#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include "token.hpp"

class Lexer {
public:
    Lexer(const std::string& code);

    Token getNextToken();

private:
    std::string code;
    size_t currentPosition;

    bool isEOF();
    char peek();
    char advance();
    void skipWhitespace();
};

#endif
