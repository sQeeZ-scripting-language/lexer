#include "lexer/token_recognizers/operator_recognizers.hpp"

void recognizeMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("MAP") && !lexer.followedByAlpha("MAP")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::MAP, 3, lexer.pos, "MAP", "ShortNotationToken::MAP",
                                       "Map function");
  }
}

void recognizeFilter(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FILTER") && !lexer.followedByAlpha("FILTER")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FILTER, 6, lexer.pos, "FILTER", "ShortNotationToken::FILTER",
                                       "Filter function");
  }
}

void recognizeReduce(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("REDUCE") && !lexer.followedByAlpha("REDUCE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REDUCE, 6, lexer.pos, "REDUCE", "ShortNotationToken::REDUCE",
                                       "Reduce function");
  }
}

void recognizeConcat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("CONCAT") && !lexer.followedByAlpha("CONCAT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::CONCAT, 6, lexer.pos, "CONCAT", "ShortNotationToken::CONCAT",
                                       "Concat function");
  }
}

void recognizeZip(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("ZIP") && !lexer.followedByAlpha("ZIP")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::ZIP, 3, lexer.pos, "ZIP", "ShortNotationToken::ZIP",
                                       "Zip function");
  }
}

void recognizeJoin(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("JOIN") && !lexer.followedByAlpha("JOIN")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::JOIN, 4, lexer.pos, "JOIN", "ShortNotationToken::JOIN",
                                       "Join function");
  }
}

void recognizeFind(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FIND") && !lexer.followedByAlpha("FIND")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FIND, 4, lexer.pos, "FIND", "ShortNotationToken::FIND",
                                       "Find function");
  }
}

void recognizeCount(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("COUNT") && !lexer.followedByAlpha("COUNT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::COUNT, 5, lexer.pos, "COUNT", "ShortNotationToken::COUNT",
                                       "Count function");
  }
}

void recognizeSort(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SORT") && !lexer.followedByAlpha("SORT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SORT, 4, lexer.pos, "SORT", "ShortNotationToken::SORT",
                                       "Sort function");
  }
}

void recognizeReverse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("REVERSE") && !lexer.followedByAlpha("REVERSE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REVERSE, 7, lexer.pos, "REVERSE",
                                       "ShortNotationToken::REVERSE", "Reverse function");
  }
}

void registerShortNotationRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["MAP"] = recognizeMap;
  tokenRecognizers["FILTER"] = recognizeFilter;
  tokenRecognizers["REDUCE"] = recognizeReduce;
  tokenRecognizers["CONCAT"] = recognizeConcat;
  tokenRecognizers["ZIP"] = recognizeZip;
  tokenRecognizers["JOIN"] = recognizeJoin;
  tokenRecognizers["FIND"] = recognizeFind;
  tokenRecognizers["COUNT"] = recognizeCount;
  tokenRecognizers["SORT"] = recognizeSort;
  tokenRecognizers["REVERSE"] = recognizeReverse;
}
