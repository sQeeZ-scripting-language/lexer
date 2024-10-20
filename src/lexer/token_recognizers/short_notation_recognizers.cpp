#include "lexer/token_recognizers/operator_recognizers.hpp"

void recognizeMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("map") && !lexer.followedByAlpha("map")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::MAP, 3, lexer.pos, "map", "ShortNotationToken::MAP", "Map function");
  }
}

void recognizeFilter(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("filter") && !lexer.followedByAlpha("filter")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FILTER, 6, lexer.pos, "filter", "ShortNotationToken::FILTER",
                                       "Filter function");
  }
}

void recognizeReduce(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("reduce") && !lexer.followedByAlpha("reduce")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REDUCE, 6, lexer.pos, "reduce", "ShortNotationToken::REDUCE",
                                       "Reduce function");
  }
}

void registerShortNotationRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["map"] = recognizeMap;
  tokenRecognizers["filter"] = recognizeFilter;
  tokenRecognizers["reduce"] = recognizeReduce;
}
