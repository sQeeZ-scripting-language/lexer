#include "lexer/token_recognizers/log_recognizers.hpp"

Token recognizeColoredLog(Lexer& lexer) {
    if (checkIfLogKeyword("logc", lexer)) return {TokenType::TOKEN_LOG_COLORED, "logc"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeBasicLog(Lexer& lexer) {
    if (checkIfLogKeyword("log", lexer)) return {TokenType::TOKEN_LOG_BASIC, "log"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeErrorLog(Lexer& lexer) {
    if (checkIfLogKeyword("error", lexer)) return {TokenType::TOKEN_LOG_ERROR, "error"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

bool checkIfLogKeyword(const std::string& keyword, Lexer& lexer) {
    bool isLogger = lexer.code.substr(lexer.currentPosition, keyword.size()) == keyword
        && lexer.currentPosition + keyword.size() < lexer.code.size()
        && lexer.code[lexer.currentPosition + keyword.size()] == '(';
    if (isLogger) lexer.currentPosition += keyword.size();
    return isLogger;
}

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["logc"] = recognizeColoredLog;
    tokenRecognizers["log"] = recognizeBasicLog;
    tokenRecognizers["error"] = recognizeErrorLog;
}
