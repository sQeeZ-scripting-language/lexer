#include "lexer/token_recognizers/log_recognizers.hpp"

Token* recognizeBasicLog(Lexer& lexer) {
  return lexer.checkKeyword("log") && !lexer.checkKeyword("logc")
             ? new Token{LogToken::BASIC, 3, "log", "Basic logging function"}
             : nullptr;
}

Token* recognizeColoredLog(Lexer& lexer) {
  return lexer.checkKeyword("logc") ? new Token{LogToken::COLORED, 4, "logc", "Colored logging function"} : nullptr;
}

Token* recognizeErrorLog(Lexer& lexer) {
  return lexer.checkKeyword("error") ? new Token{LogToken::ERROR, 5, "error", "Error logging function"} : nullptr;
}

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["log"] = recognizeBasicLog;
  tokenRecognizers["logc"] = recognizeColoredLog;
  tokenRecognizers["error"] = recognizeErrorLog;
}
