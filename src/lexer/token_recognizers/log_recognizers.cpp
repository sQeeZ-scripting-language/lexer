#include "lexer/token_recognizers/log_recognizers.hpp"

Token recognizeBasicLog(Lexer& lexer) {
    if (lexer.checkKeyword("log") && !lexer.checkKeyword("logc")) {
        lexer.skip(3);
        return {TokenType::TOKEN_LOG_BASIC, "log", "Basic logging function"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeColoredLog(Lexer& lexer) {
    if (lexer.checkKeyword("logc")) {
        lexer.skip(4);
        return {TokenType::TOKEN_LOG_COLORED, "logc", "Colored logging function"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeErrorLog(Lexer& lexer) {
    if (lexer.checkKeyword("error")) {
        lexer.skip(5);
        return {TokenType::TOKEN_LOG_ERROR, "error", "Error logging function"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["log"] = recognizeBasicLog;
    tokenRecognizers["logc"] = recognizeColoredLog;
    tokenRecognizers["error"] = recognizeErrorLog;
}
