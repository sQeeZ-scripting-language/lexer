#include "lexer/token_recognizers/log_recognizers.hpp"

void recognizeBasicLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("log") && !lexer.checkKeyword("logc")) {
    tokenPtr = std::make_unique<Token>(LogToken::BASIC, 3, "log", "Basic logging function");
  }
}

void recognizeColoredLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("logc")) {
    tokenPtr = std::make_unique<Token>(LogToken::COLORED, 4, "logc", "Colored logging function");
  }
}

void recognizeWarnLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("warn")) {
    tokenPtr = std::make_unique<Token>(LogToken::WARN, 4, "warn", "Warning logging function");
  }
}

void recognizeErrorLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("error")) {
    tokenPtr = std::make_unique<Token>(LogToken::ERROR, 5, "error", "Error logging function");
  }
}

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["log"] = recognizeBasicLog;
  tokenRecognizers["logc"] = recognizeColoredLog;
  tokenRecognizers["warn"] = recognizeWarnLog;
  tokenRecognizers["error"] = recognizeErrorLog;
}
