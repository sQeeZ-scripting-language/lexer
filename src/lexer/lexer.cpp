#include "lexer/lexer.hpp"
#include "lexer/token_recognizers/syntax_recognizers.hpp"
#include "lexer/token_recognizers/keyword_recognizers.hpp"
#include "lexer/token_recognizers/operator_recognizers.hpp"
#include "lexer/token_recognizers/logical_recognizers.hpp"
#include "lexer/token_recognizers/log_recognizers.hpp"

Lexer::Lexer(const std::string& code) : code(code), currentPosition(0), functions(), variables() {
    registerTokenRecognizers();
}

void Lexer::registerTokenRecognizers() {
    registerSyntaxRecognizers(tokenRecognizers);
    registerKeywordRecognizers(tokenRecognizers);
    registerOperatorRecognizers(tokenRecognizers);
    registerLogicalRecognizers(tokenRecognizers);
    registerLogRecognizers(tokenRecognizers);
}

Token Lexer::getNextToken() {
    skipWhitespace();
    if (isEOF()) {
        return {TokenType::TOKEN_EOF, "EOF", "The end of the file"};
    }

    for (const auto& recognizer : tokenRecognizers) {
        size_t originalPosition = currentPosition;
        Token token = recognizer.second(*this);
        if (token.type != TokenType::TOKEN_UNKNOWN) return token;
        currentPosition = originalPosition;
    }

    char currentChar = peek();
    advance();
    return {TokenType::TOKEN_UNKNOWN, std::string(1, currentChar), "Unknown"};
}

Token Lexer::getFunctionName() {
    skipWhitespace();
    size_t i = code.find(' ', currentPosition);
    std::string name = (i == std::string::npos) ? code.substr(currentPosition, i - currentPosition) : code.substr(currentPosition);
    bool isFunction = checkName(functions, name);
    return {isFunction ? TokenType::TOKEN_FUNCTION_NAME : TokenType::TOKEN_UNKNOWN, name, isFunction ? "Function name" : "Unknown"};
}

Token Lexer::getVariableName() {
    skipWhitespace();
    size_t i = code.find(' ', currentPosition);
    std::string name = (i == std::string::npos) ? code.substr(currentPosition, i - currentPosition) : code.substr(currentPosition);
    bool isVariable = checkName(variables, name);
    return {isVariable ? TokenType::TOKEN_VARIABLE_NAME : TokenType::TOKEN_UNKNOWN, name, isVariable ? "Variable name" : "Unknown"};
}

bool Lexer::checkKeyword(const std::string& keyword) {
    return code.substr(currentPosition, keyword.size()) == keyword;
}

bool Lexer::checkName(const std::unordered_map<std::string, std::string>& map, const std::string& name) {
    return map.find(name) != map.end();
}

void Lexer::skip(size_t size) {
    currentPosition += size;
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
