#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <cctype>
#include <unordered_map>
#include "token.hpp"

class Lexer {
public:
    Lexer(const std::string& code);
    Token getNextToken();
    bool checkKeyword(const std::string& keyword);
    void skip(size_t size);
    
    const std::string code;
    size_t currentPosition;
    std::unordered_map<std::string, Token(*)(Lexer&)> tokenRecognizers;

private:
    void registerTokenRecognizers();
    void skipWhitespace();
    bool isEOF();
    char peek();
    char advance();
};

#endif
