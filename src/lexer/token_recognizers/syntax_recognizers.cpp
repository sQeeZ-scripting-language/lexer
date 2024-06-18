#include "lexer/token_recognizers/syntax_recognizers.hpp"

Token recognizeAssign(Lexer& lexer) {
    if (checkIfSyntaxKeyword("=", lexer)) return {TokenType::TOKEN_LOG_ERROR, "="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeComma(Lexer& lexer) {
    if (checkIfSyntaxKeyword(",", lexer)) return {TokenType::TOKEN_COMMA, ","};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeSemicolon(Lexer& lexer) {
    if (checkIfSyntaxKeyword(";", lexer)) return {TokenType::TOKEN_SEMICOLON, ";"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeSingleQuote(Lexer& lexer) {
    if (checkIfSyntaxKeyword("'", lexer)) return {TokenType::TOKEN_SINGLE_QUOTE, "'"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDoubleQuote(Lexer& lexer) {
    if (checkIfSyntaxKeyword("\"", lexer)) return {TokenType::TOKEN_DOUBLE_QUOTE, "\""};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeOpenParenthesis(Lexer& lexer) {
    if (checkIfSyntaxKeyword("(", lexer)) return {TokenType::TOKEN_OPEN_PARENTHESIS, "("};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeCloseParenthesis(Lexer& lexer) {
    if (checkIfSyntaxKeyword(")", lexer)) return {TokenType::TOKEN_CLOSE_PARENTHESIS, ")"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeOpenBracket(Lexer& lexer) {
    if (checkIfSyntaxKeyword("[", lexer)) return {TokenType::TOKEN_OPEN_BRACKET, "["};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeCloseBracket(Lexer& lexer) {
    if (checkIfSyntaxKeyword("]", lexer)) return {TokenType::TOKEN_CLOSE_BRACKET, "]"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeOpenBrace(Lexer& lexer) {
    if (checkIfSyntaxKeyword("{", lexer)) return {TokenType::TOKEN_OPEN_BRACE, "{"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeCloseBrace(Lexer& lexer) {
    if (checkIfSyntaxKeyword("}", lexer)) return {TokenType::TOKEN_CLOSE_BRACE, "}"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDot(Lexer& lexer) {
    if (checkIfSyntaxKeyword(".", lexer)) return {TokenType::TOKEN_DOT, "."};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeArrow(Lexer& lexer) {
    if (checkIfSyntaxKeyword("->", lexer)) return {TokenType::TOKEN_ARROW, "->"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

bool checkIfSyntaxKeyword(const std::string& keyword, Lexer& lexer) {
    bool isLogger = lexer.code.substr(lexer.currentPosition, keyword.size()) == keyword
        && lexer.currentPosition + keyword.size() < lexer.code.size();
    if (isLogger) lexer.currentPosition += keyword.size();
    return isLogger;
}

void registerSyntaxRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["="] = recognizeAssign;
}
