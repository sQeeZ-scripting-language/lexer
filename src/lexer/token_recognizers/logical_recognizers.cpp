#include "lexer/token_recognizers/logical_recognizers.hpp"

Token recognizeEqual(Lexer& lexer) {
    if (checkIfLogicalOperator("==", lexer)) return {TokenType::TOKEN_EQUAL, "=="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeNotEqual(Lexer& lexer) {
    if (checkIfLogicalOperator("!=", lexer)) return {TokenType::TOKEN_NOT_EQUAL, "!="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeGreater(Lexer& lexer) {
    if (checkIfLogicalOperator(">", lexer)) return {TokenType::TOKEN_GREATER, ">"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeLess(Lexer& lexer) {
    if (checkIfLogicalOperator("<", lexer)) return {TokenType::TOKEN_LESS, "<"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeGreaterEqual(Lexer& lexer) {
    if (checkIfLogicalOperator(">=", lexer)) return {TokenType::TOKEN_GREATER_EQUAL, ">="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeLessEqual(Lexer& lexer) {
    if (checkIfLogicalOperator("<=", lexer)) return {TokenType::TOKEN_LESS_EQUAL, "<="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeAnd(Lexer& lexer) {
    if (checkIfLogicalOperator("&&", lexer)) return {TokenType::TOKEN_AND, "&&"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeOr(Lexer& lexer) {
    if (checkIfLogicalOperator("||", lexer)) return {TokenType::TOKEN_OR, "||"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeNot(Lexer& lexer) {
    if (checkIfLogicalOperator("!", lexer)) return {TokenType::TOKEN_NOT, "!"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

bool checkIfLogicalOperator(const std::string& keyword, Lexer& lexer) {
    bool isLogicalOperator = lexer.code.substr(lexer.currentPosition, keyword.size()) == keyword
        && lexer.currentPosition + keyword.size() < lexer.code.size();
    if (isLogicalOperator) lexer.currentPosition += keyword.size();
    return isLogicalOperator;
}

void registerLogicalRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["=="] = recognizeEqual;
    tokenRecognizers["!="] = recognizeNotEqual;
    tokenRecognizers[">"] = recognizeGreater;
    tokenRecognizers["<"] = recognizeLess;
    tokenRecognizers[">="] = recognizeGreaterEqual;
    tokenRecognizers["<="] = recognizeLessEqual;
    tokenRecognizers["&&"] = recognizeAnd;
    tokenRecognizers["||"] = recognizeOr;
    tokenRecognizers["!"] = recognizeNot;
}
