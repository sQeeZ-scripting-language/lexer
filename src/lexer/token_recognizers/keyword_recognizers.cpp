#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token recognizeIfKeyword(Lexer& lexer) {
    if (checkIfKeyword("if", lexer)) return {TokenType::TOKEN_IF, "if"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeElseKeyword(Lexer& lexer) {
    if (checkIfKeyword("else", lexer)) return {TokenType::TOKEN_ELSE, "else"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeElseIfKeyword(Lexer& lexer) {
    if (checkIfKeyword("elif", lexer)) return {TokenType::TOKEN_ELSE_IF, "elif"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeForKeyword(Lexer& lexer) {
    if (checkIfKeyword("for", lexer)) return {TokenType::TOKEN_FOR, "for"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeInKeyword(Lexer& lexer) {
    if (checkIfKeyword("in", lexer)) return {TokenType::TOKEN_IN, "in"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeBreakKeyword(Lexer& lexer) {
    if (checkIfKeyword("break", lexer)) return {TokenType::TOKEN_BREAK, "break"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeContinueKeyword(Lexer& lexer) {
    if (checkIfKeyword("continue", lexer)) return {TokenType::TOKEN_CONTINUE, "continue"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeReturnKeyword(Lexer& lexer) {
    if (checkIfKeyword("return", lexer)) return {TokenType::TOKEN_RETURN, "return"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeFunctionKeyword(Lexer& lexer) {
    if (checkIfKeyword("fn", lexer)) return {TokenType::TOKEN_FUNCTION, "fn"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeLetKeyword(Lexer& lexer) {
    if (checkIfKeyword("let", lexer)) return {TokenType::TOKEN_LET, "let"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeConstKeyword(Lexer& lexer) {
    if (checkIfKeyword("const", lexer)) return {TokenType::TOKEN_CONST, "const"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

bool checkIfKeyword(const std::string& keyword, Lexer& lexer) {
    bool isKeyword = lexer.code.substr(lexer.currentPosition, keyword.size()) == keyword
        && lexer.currentPosition + keyword.size() < lexer.code.size()
        && isspace(lexer.code[lexer.currentPosition + keyword.size()]);
    if (isKeyword) lexer.currentPosition += keyword.size();
    return isKeyword;
}

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["if"] = recognizeIfKeyword;
    tokenRecognizers["else"] = recognizeElseKeyword;
    tokenRecognizers["elif"] = recognizeElseIfKeyword;
    tokenRecognizers["for"] = recognizeForKeyword;
    tokenRecognizers["in"] = recognizeInKeyword;
    tokenRecognizers["break"] = recognizeBreakKeyword;
    tokenRecognizers["continue"] = recognizeContinueKeyword;
    tokenRecognizers["return"] = recognizeReturnKeyword;
    tokenRecognizers["fn"] = recognizeFunctionKeyword;
    tokenRecognizers["let"] = recognizeLetKeyword;
    tokenRecognizers["const"] = recognizeConstKeyword;
}
