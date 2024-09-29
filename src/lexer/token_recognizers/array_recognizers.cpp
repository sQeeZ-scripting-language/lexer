#include "lexer/token_recognizers/array_recognizers.hpp"

void recognizeLength(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("length")) {
    tokenPtr =
        std::make_unique<Token>(ArrayToken::LENGTH, 6, "length", "ArrayToken::LENGTH", "Get the length of an array");
  }
}

void recognizePush(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("push")) {
    tokenPtr =
        std::make_unique<Token>(ArrayToken::PUSH, 4, "push", "ArrayToken::PUSH", "Push item to the end of an array");
  }
}

void recognizePop(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("pop")) {
    tokenPtr =
        std::make_unique<Token>(ArrayToken::POP, 3, "pop", "ArrayToken::POP", "Pop item from the end of an array");
  }
}

void recognizeShift(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("shift")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::SHIFT, 5, "shift", "ArrayToken::SHIFT",
                                       "Shift item from the beginning of an array");
  }
}

void recognizeUnshift(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("unshift")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::UNSHIFT, 7, "unshift", "ArrayToken::UNSHIFT",
                                       "Unshift item to the beginning of an array");
  }
}

void recognizeSplice(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("splice")) {
    tokenPtr =
        std::make_unique<Token>(ArrayToken::SPLICE, 6, "splice", "ArrayToken::SPLICE", "Splice items into an array");
  }
}

void recognizeSlice(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("slice")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::SLICE, 5, "slice", "ArrayToken::SLICE", "Slice items from an array");
  }
}

void recognizeConcat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("concat")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::CONCAT, 6, "concat", "ArrayToken::CONCAT", "Concatenate arrays");
  }
}

void recognizeJoin(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("join")) {
    tokenPtr =
        std::make_unique<Token>(ArrayToken::JOIN, 4, "join", "ArrayToken::JOIN", "Join array elements into a string");
  }
}

void recognizeReverse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("reverse")) {
    tokenPtr =
        std::make_unique<Token>(ArrayToken::REVERSE, 7, "reverse", "ArrayToken::REVERSE", "Reverse array elements");
  }
}

void recognizeSort(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("sort")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::SORT, 4, "sort", "ArrayToken::SORT", "Sort array elements");
  }
}

void recognizeMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("map")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::MAP, 3, "map", "ArrayToken::MAP", "Map array elements");
  }
}

void recognizeFilter(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("filter")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::FILTER, 6, "filter", "ArrayToken::FILTER", "Filter array elements");
  }
}

void recognizeReduce(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("reduce")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::REDUCE, 6, "reduce", "ArrayToken::REDUCE", "Reduce array elements");
  }
}

void recognizeIncludes(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("includes")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::INCLUDES, 8, "includes", "ArrayToken::INCLUDES",
                                       "Check if an array includes an element");
  }
}

void recognizeForEach(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("forEach")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::FOR_EACH, 7, "forEach", "ArrayToken::FOR_EACH",
                                       "Iterate over array elements");
  }
}

void recognizeIndexOf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("indexOf")) {
    tokenPtr = std::make_unique<Token>(ArrayToken::INDEX_OF, 7, "indexOf", "ArrayToken::INDEX_OF",
                                       "Find index of an element in an array");
  }
}

void registerArrayRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["length"] = recognizeLength;
  tokenRecognizers["push"] = recognizePush;
  tokenRecognizers["pop"] = recognizePop;
  tokenRecognizers["shift"] = recognizeShift;
  tokenRecognizers["unshift"] = recognizeUnshift;
  tokenRecognizers["splice"] = recognizeSplice;
  tokenRecognizers["slice"] = recognizeSlice;
  tokenRecognizers["concat"] = recognizeConcat;
  tokenRecognizers["join"] = recognizeJoin;
  tokenRecognizers["reverse"] = recognizeReverse;
  tokenRecognizers["sort"] = recognizeSort;
  tokenRecognizers["map"] = recognizeMap;
  tokenRecognizers["filter"] = recognizeFilter;
  tokenRecognizers["reduce"] = recognizeReduce;
  tokenRecognizers["includes"] = recognizeIncludes;
  tokenRecognizers["forEach"] = recognizeForEach;
  tokenRecognizers["indexOf"] = recognizeIndexOf;
}