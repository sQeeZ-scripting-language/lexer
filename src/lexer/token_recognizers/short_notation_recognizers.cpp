#include "lexer/token_recognizers/operator_recognizers.hpp"

void recognizeMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("map") && !lexer.followedByAlpha("map")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::MAP, 3, lexer.pos, "map", "ShortNotationToken::MAP",
                                       "Map function");
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

void recognizeConcat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("concat") && !lexer.followedByAlpha("concat")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::CONCAT, 6, lexer.pos, "concat", "ShortNotationToken::CONCAT",
                                       "Concat function");
  }
}

void recognizeZip(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("zip") && !lexer.followedByAlpha("zip")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::ZIP, 3, lexer.pos, "zip", "ShortNotationToken::ZIP",
                                       "Zip function");
  }
}

void recognizeJoin(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("join") && !lexer.followedByAlpha("join")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::JOIN, 4, lexer.pos, "join", "ShortNotationToken::JOIN",
                                       "Join function");
  }
}

void recognizeFind(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("find") && !lexer.followedByAlpha("find")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FIND, 4, lexer.pos, "find", "ShortNotationToken::FIND",
                                       "Find function");
  }
}

void recognizeCount(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("count") && !lexer.followedByAlpha("count")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::COUNT, 5, lexer.pos, "count", "ShortNotationToken::COUNT",
                                       "Count function");
  }
}

void recognizeSort(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("sort") && !lexer.followedByAlpha("sort")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SORT, 4, lexer.pos, "sort", "ShortNotationToken::SORT",
                                       "Sort function");
  }
}

void recognizeReverse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("reverse") && !lexer.followedByAlpha("reverse")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REVERSE, 7, lexer.pos, "reverse",
                                       "ShortNotationToken::REVERSE", "Reverse function");
  }
}

void registerShortNotationRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["map"] = recognizeMap;
  tokenRecognizers["filter"] = recognizeFilter;
  tokenRecognizers["reduce"] = recognizeReduce;
  tokenRecognizers["concat"] = recognizeConcat;
  tokenRecognizers["zip"] = recognizeZip;
  tokenRecognizers["join"] = recognizeJoin;
  tokenRecognizers["find"] = recognizeFind;
  tokenRecognizers["count"] = recognizeCount;
  tokenRecognizers["sort"] = recognizeSort;
  tokenRecognizers["reverse"] = recognizeReverse;
}
