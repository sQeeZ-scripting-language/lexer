#include "lexer/lexer.hpp"
#include "lexer/token_recognizers/keyword_recognizers.hpp"
#include "lexer/token_recognizers/syntax_recognizers.hpp"
#include "lexer/token_recognizers/logical_recognizers.hpp"
#include "lexer/token_recognizers/operator_recognizers.hpp"
#include "lexer/token_recognizers/log_recognizers.hpp"

Lexer::Lexer(const std::string& code) : code(code), currentPosition(0) {
    registerTokenRecognizers();
}

void Lexer::registerTokenRecognizers() {
    registerKeywordRecognizers(tokenRecognizers);
    registerSyntaxRecognizers(tokenRecognizers);
    registerLogicalRecognizers(tokenRecognizers);
    registerOperatorRecognizers(tokenRecognizers);
    registerLogRecognizers(tokenRecognizers);
}

Token Lexer::getNextToken() {
    skipWhitespace();
    if (isEOF()) {
        return {TokenType::TOKEN_EOF, "EOF"};
    }

    for (const auto& recognizer : tokenRecognizers) {
        size_t originalPosition = currentPosition;
        Token token = recognizer.second(*this);
        if (token.type != TokenType::TOKEN_UNKNOWN) return token;
        currentPosition = originalPosition;
    }

    char currentChar = peek();
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
