#include "lexer/token_recognizers/log_recognizers.hpp"

Token recognizeBasicLog(Lexer& lexer) {
  if (lexer.checkKeyword("<>") && !lexer.checkKeyword("logc")) {
    lexer.skip(2);
    return {TokenType::TOKEN_LOG_BASIC, "<>", "Basic logging function"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeColoredLog(Lexer& lexer) {
  if (lexer.checkKeyword("<#>")) {
    lexer.skip(3);
    return {TokenType::TOKEN_LOG_COLORED, "<#>", "Colored logging function"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeErrorLog(Lexer& lexer) {
  if (lexer.checkKeyword("<!>")) {
    lexer.skip(3);
    return {TokenType::TOKEN_LOG_ERROR, "<!>", "Error logging function"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["<>"] = recognizeBasicLog;
  tokenRecognizers["<#>"] = recognizeColoredLog;
  tokenRecognizers["<!>"] = recognizeErrorLog;
}
