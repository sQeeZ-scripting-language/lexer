#include "lexer/token_recognizers/log_recognizers.hpp"

void recognizeBasicLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("log") && !lexer.checkKeyword("logc") && !lexer.followedByAlpha("log")) {
    tokenPtr =
        std::make_unique<Token>(LogToken::BASIC, 3, lexer.pos, "log", "LogToken::BASIC", "Basic logging function");
  }
}

void recognizeColoredLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("logc") && !lexer.followedByAlpha("logc") && !lexer.followedByAlpha("logc")) {
    tokenPtr = std::make_unique<Token>(LogToken::COLORED, 4, lexer.pos, "logc", "LogToken::COLORED",
                                       "Colored logging function");
  }
}

void recognizeWarnLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("warn") && !lexer.followedByAlpha("warn")) {
    tokenPtr =
        std::make_unique<Token>(LogToken::WARN, 4, lexer.pos, "warn", "LogToken::WARN", "Warning logging function");
  }
}

void recognizeErrorLog(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("error") && !lexer.followedByAlpha("error")) {
    tokenPtr =
        std::make_unique<Token>(LogToken::ERROR, 5, lexer.pos, "error", "LogToken::ERROR", "Error logging function");
  }
}

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["log"] = recognizeBasicLog;
  tokenRecognizers["logc"] = recognizeColoredLog;
  tokenRecognizers["warn"] = recognizeWarnLog;
  tokenRecognizers["error"] = recognizeErrorLog;
}
