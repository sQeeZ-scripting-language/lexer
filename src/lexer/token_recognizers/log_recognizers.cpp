#include "lexer/token_recognizers/log_recognizers.hpp"

Token recognizeBasicLog(Lexer& lexer) {
  if (lexer.checkKeyword("log") && !lexer.checkKeyword("logc")) {
    lexer.skip(3);
    return {LogToken::BASIC, "log", "Basic logging function"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeColoredLog(Lexer& lexer) {
  if (lexer.checkKeyword("logc")) {
    lexer.skip(4);
    return {LogToken::COLORED, "logc", "Colored logging function"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeErrorLog(Lexer& lexer) {
  if (lexer.checkKeyword("error")) {
    lexer.skip(5);
    return {LogToken::ERROR, "error", "Error logging function"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["log"] = recognizeBasicLog;
  tokenRecognizers["logc"] = recognizeColoredLog;
  tokenRecognizers["error"] = recognizeErrorLog;
}
