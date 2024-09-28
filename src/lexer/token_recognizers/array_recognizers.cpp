#include "lexer/token_recognizers/array_recognizers.hpp"

void recognizePush(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("push")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::PUSH, 4, "push", "ArrayToken::PUSH", "Push item to the end of an array");
  }
}

void registerArrayRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["push"] = recognizePush;
}