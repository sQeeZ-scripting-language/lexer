#include "lexer/lexer.hpp"
#include <cctype>

Lexer::Lexer(const std::string& code) : code(code), currentPosition(0) { }

Token Lexer::getNextToken() {
    skipWhitespace();
    if (isEOF()) {
        return {TokenType::TOKEN_EOF, ""};
    }

    char currentChar = peek();
    if (currentChar == 'l' && code.substr(currentPosition, 3) == "log") {
        return {TokenType::TOKEN_LOG, "log"};
    }
    advance();
    return {TokenType::TOKEN_UNKNOWN, std::string(1, currentChar)};
}

bool Lexer::isEOF() {
    return currentPosition >= code.size();
}

char Lexer::peek() {
    if (isEOF()) {
        return '\0';
    }
    return code[currentPosition];
}

char Lexer::advance() {
    if (!isEOF()) {
        currentPosition++;
    }
    return peek();
}

void Lexer::skipWhitespace() {
    while (!isEOF() && std::isspace(peek())) {
        advance();
    }
}
