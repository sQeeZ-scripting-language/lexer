#include "lexer/token_recognizers/operator_recognizers.hpp"

void recognizeLength(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("LENGTH") && !lexer.followedByAlpha("LENGTH")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::LENGTH, 6, lexer.pos, "LENGTH", "ShortNotationToken::LENGTH",
                                       "Length function");
  }
}

void recognizeConcat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("CONCAT") && !lexer.followedByAlpha("CONCAT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::CONCAT, 6, lexer.pos, "CONCAT", "ShortNotationToken::CONCAT",
                                       "Concat function");
  }
}

void recognizeIncludes(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("INCLUDES") && !lexer.followedByAlpha("INCLUDES")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::INCLUDES, 8, lexer.pos, "INCLUDES",
                                       "ShortNotationToken::INCLUDES", "Includes function");
  }
}

void recognizeIndexOf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("INDEX_OF") && !lexer.followedByAlpha("INDEX_OF")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::INDEX_OF, 8, lexer.pos, "INDEX_OF",
                                       "ShortNotationToken::INDEX_OF", "Index of function");
  }
}

void recognizeLastIndexOf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("LAST_INDEX_OF") && !lexer.followedByAlpha("LAST_INDEX_OF")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::LAST_INDEX_OF, 13, lexer.pos, "LAST_INDEX_OF",
                                       "ShortNotationToken::LAST_INDEX_OF", "Last index of function");
  }
}

void recognizeSlice(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SLICE") && !lexer.followedByAlpha("SLICE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SLICE, 5, lexer.pos, "SLICE", "ShortNotationToken::SLICE",
                                       "Slice function");
  }
}

void recognizePush(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("PUSH") && !lexer.followedByAlpha("PUSH")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::PUSH, 4, lexer.pos, "PUSH", "ShortNotationToken::PUSH",
                                       "Push function");
  }
}

void recognizePop(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("POP") && !lexer.followedByAlpha("POP")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::POP, 3, lexer.pos, "POP", "ShortNotationToken::POP",
                                       "Pop function");
  }
}

void recognizeShift(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SHIFT") && !lexer.followedByAlpha("SHIFT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SHIFT, 5, lexer.pos, "SHIFT", "ShortNotationToken::SHIFT",
                                       "Shift function");
  }
}

void recognizeUnshift(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("UNSHIFT") && !lexer.followedByAlpha("UNSHIFT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::UNSHIFT, 7, lexer.pos, "UNSHIFT",
                                       "ShortNotationToken::UNSHIFT", "Unshift function");
  }
}

void recognizeSplice(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SPLICE") && !lexer.followedByAlpha("SPLICE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SPLICE, 6, lexer.pos, "SPLICE", "ShortNotationToken::SPLICE",
                                       "Splice function");
  }
}

void recognizeReverse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("REVERSE") && !lexer.followedByAlpha("REVERSE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REVERSE, 7, lexer.pos, "REVERSE",
                                       "ShortNotationToken::REVERSE", "Reverse function");
  }
}

void recognizeSort(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SORT") && !lexer.followedByAlpha("SORT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SORT, 4, lexer.pos, "SORT", "ShortNotationToken::SORT",
                                       "Sort function");
  }
}

void recognizeFill(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FILL") && !lexer.followedByAlpha("FILL")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FILL, 4, lexer.pos, "FILL", "ShortNotationToken::FILL",
                                       "Fill function");
  }
}

void recognizeJoin(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("JOIN") && !lexer.followedByAlpha("JOIN")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::JOIN, 4, lexer.pos, "JOIN", "ShortNotationToken::JOIN",
                                       "Join function");
  }
}

void recognizeEvery(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("EVERY") && !lexer.followedByAlpha("EVERY")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::EVERY, 5, lexer.pos, "EVERY", "ShortNotationToken::EVERY",
                                       "Every function");
  }
}

void recognizeSome(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SOME") && !lexer.followedByAlpha("SOME")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SOME, 4, lexer.pos, "SOME", "ShortNotationToken::SOME",
                                       "Some function");
  }
}

void recognizeFind(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FIND") && !lexer.checkKeyword("FIND_INDEX") && !lexer.checkKeyword("FIND_LAST") &&
      !lexer.checkKeyword("FIND_LAST_INDEX") && !lexer.followedByAlpha("FIND")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FIND, 4, lexer.pos, "FIND", "ShortNotationToken::FIND",
                                       "Find function");
  }
}

void recognizeFindIndex(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FIND_INDEX") && !lexer.followedByAlpha("FIND_INDEX")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FIND_INDEX, 10, lexer.pos, "FIND_INDEX",
                                       "ShortNotationToken::FIND_INDEX", "Find index function");
  }
}

void recognizeFindLast(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FIND_LAST") && !lexer.checkKeyword("FIND_LAST_INDEX") &&
      !lexer.followedByAlpha("FIND_LAST")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FIND_LAST, 9, lexer.pos, "FIND_LAST",
                                       "ShortNotationToken::FIND_LAST", "Find last function");
  }
}

void recognizeFindLastIndex(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FIND_LAST_INDEX") && !lexer.followedByAlpha("FIND_LAST_INDEX")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FIND_LAST_INDEX, 15, lexer.pos, "FIND_LAST_INDEX",
                                       "ShortNotationToken::FIND_LAST_INDEX", "Find last index function");
  }
}

void recognizeFilter(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FILTER") && !lexer.followedByAlpha("FILTER")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FILTER, 6, lexer.pos, "FILTER", "ShortNotationToken::FILTER",
                                       "Filter function");
  }
}

void recognizeMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("MAP") && !lexer.followedByAlpha("MAP")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::MAP, 3, lexer.pos, "MAP", "ShortNotationToken::MAP",
                                       "Map function");
  }
}

void recognizeReduce(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("REDUCE") && !lexer.followedByAlpha("REDUCE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REDUCE, 6, lexer.pos, "REDUCE", "ShortNotationToken::REDUCE",
                                       "Reduce function");
  }
}

void recognizeFlat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FLAT") && !lexer.checkKeyword("FLAT_MAP") && !lexer.followedByAlpha("FLAT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FLAT, 4, lexer.pos, "FLAT", "ShortNotationToken::FLAT",
                                       "Flat function");
  }
}

void recognizeFlatMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FLAT_MAP") && !lexer.followedByAlpha("FLAT_MAP")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FLAT_MAP, 8, lexer.pos, "FLAT_MAP",
                                       "ShortNotationToken::FLAT_MAP", "Flat map function");
  }
}

void recognizeForEach(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("FOR_EACH") && !lexer.followedByAlpha("FOR_EACH")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::FOR_EACH, 8, lexer.pos, "FOR_EACH",
                                       "ShortNotationToken::FOR_EACH", "For each function");
  }
}

void recognizeHasKey(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("HAS_KEY") && !lexer.followedByAlpha("HAS_KEY")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::HAS_KEY, 7, lexer.pos, "HAS_KEY",
                                       "ShortNotationToken::HAS_KEY", "Has key function");
  }
}

void recognizeKeys(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("KEYS") && !lexer.followedByAlpha("KEYS")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::KEYS, 4, lexer.pos, "KEYS", "ShortNotationToken::KEYS",
                                       "Keys function");
  }
}

void recognizeValues(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("VALUES") && !lexer.followedByAlpha("VALUES")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::VALUES, 6, lexer.pos, "VALUES", "ShortNotationToken::VALUES",
                                       "Values function");
  }
}

void recognizeEntries(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("ENTRIES") && !lexer.followedByAlpha("ENTRIES")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::ENTRIES, 7, lexer.pos, "ENTRIES",
                                       "ShortNotationToken::ENTRIES", "Entries function");
  }
}

void recognizeGet(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("GET") && !lexer.followedByAlpha("GET")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::GET, 3, lexer.pos, "GET", "ShortNotationToken::GET",
                                       "Get function");
  }
}

void recognizeCharAt(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("CHAR_AT") && !lexer.followedByAlpha("CHAR_AT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::CHAR_AT, 7, lexer.pos, "CHAR_AT",
                                       "ShortNotationToken::CHAR_AT", "Char at function");
  }
}

void recognizeCharCodeAt(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("CHAR_CODE_AT") && !lexer.followedByAlpha("CHAR_CODE_AT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::CHAR_CODE_AT, 12, lexer.pos, "CHAR_CODE_AT",
                                       "ShortNotationToken::CHAR_CODE_AT", "Char code at function");
  }
}

void recognizeMatch(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("MATCH") && !lexer.followedByAlpha("MATCH")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::MATCH, 5, lexer.pos, "MATCH", "ShortNotationToken::MATCH",
                                       "Match function");
  }
}

void recognizeMatchAll(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("MATCH_ALL") && !lexer.followedByAlpha("MATCH_ALL")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::MATCH_ALL, 9, lexer.pos, "MATCH_ALL",
                                       "ShortNotationToken::MATCH_ALL", "Match all function");
  }
}

void recognizePadEnd(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("PAD_END") && !lexer.followedByAlpha("PAD_END")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::PAD_END, 7, lexer.pos, "PAD_END",
                                       "ShortNotationToken::PAD_END", "Pad end function");
  }
}

void recognizePadStart(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("PAD_START") && !lexer.followedByAlpha("PAD_START")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::PAD_START, 9, lexer.pos, "PAD_START",
                                       "ShortNotationToken::PAD_START", "Pad start function");
  }
}

void recognizeRepeat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("REPEAT") && !lexer.followedByAlpha("REPEAT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REPEAT, 6, lexer.pos, "REPEAT", "ShortNotationToken::REPEAT",
                                       "Repeat function");
  }
}

void recognizeReplace(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("REPLACE") && !lexer.followedByAlpha("REPLACE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REPLACE, 7, lexer.pos, "REPLACE",
                                       "ShortNotationToken::REPLACE", "Replace function");
  }
}

void recognizeReplaceAll(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("REPLACE_ALL") && !lexer.followedByAlpha("REPLACE_ALL")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::REPLACE_ALL, 11, lexer.pos, "REPLACE_ALL",
                                       "ShortNotationToken::REPLACE_ALL", "Replace all function");
  }
}

void recognizeSplit(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SPLIT") && !lexer.followedByAlpha("SPLIT")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SPLIT, 5, lexer.pos, "SPLIT", "ShortNotationToken::SPLIT",
                                       "Split function");
  }
}

void recognizeStartsWith(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("STARTS_WITH") && !lexer.followedByAlpha("STARTS_WITH")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::STARTS_WITH, 11, lexer.pos, "STARTS_WITH",
                                       "ShortNotationToken::STARTS_WITH", "Starts with function");
  }
}

void recognizeEndsWith(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("ENDS_WITH") && !lexer.followedByAlpha("ENDS_WITH")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::ENDS_WITH, 9, lexer.pos, "ENDS_WITH",
                                       "ShortNotationToken::ENDS_WITH", "Ends with function");
  }
}

void recognizeSubstring(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("SUBSTRING") && !lexer.followedByAlpha("SUBSTRING")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::SUBSTRING, 9, lexer.pos, "SUBSTRING",
                                       "ShortNotationToken::SUBSTRING", "Substring function");
  }
}

void recognizeLowercase(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("LOWERCASE") && !lexer.followedByAlpha("LOWERCASE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::LOWERCASE, 9, lexer.pos, "LOWERCASE",
                                       "ShortNotationToken::LOWERCASE", "Lowercase function");
  }
}

void recognizeUppercase(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("UPPERCASE") && !lexer.followedByAlpha("UPPERCASE")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::UPPERCASE, 9, lexer.pos, "UPPERCASE",
                                       "ShortNotationToken::UPPERCASE", "Uppercase function");
  }
}

void recognizeTrim(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("TRIM") && !lexer.checkKeyword("TRIM_END") && !lexer.checkKeyword("TRIM_START") &&
      !lexer.followedByAlpha("TRIM")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::TRIM, 4, lexer.pos, "TRIM", "ShortNotationToken::TRIM",
                                       "Trim function");
  }
}

void recognizeTrimEnd(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("TRIM_END") && !lexer.followedByAlpha("TRIM_END")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::TRIM_END, 8, lexer.pos, "TRIM_END",
                                       "ShortNotationToken::TRIM_END", "Trim end function");
  }
}

void recognizeTrimStart(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("TRIM_START") && !lexer.followedByAlpha("TRIM_START")) {
    tokenPtr = std::make_unique<Token>(ShortNotationToken::TRIM_START, 10, lexer.pos, "TRIM_START",
                                       "ShortNotationToken::TRIM_START", "Trim start function");
  }
}

void registerShortNotationRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["LENGTH"] = recognizeLength;
  tokenRecognizers["CONCAT"] = recognizeConcat;
  tokenRecognizers["INCLUDES"] = recognizeIncludes;
  tokenRecognizers["INDEX_OF"] = recognizeIndexOf;
  tokenRecognizers["LAST_INDEX_OF"] = recognizeLastIndexOf;
  tokenRecognizers["SLICE"] = recognizeSlice;
  tokenRecognizers["PUSH"] = recognizePush;
  tokenRecognizers["POP"] = recognizePop;
  tokenRecognizers["SHIFT"] = recognizeShift;
  tokenRecognizers["UNSHIFT"] = recognizeUnshift;
  tokenRecognizers["SPLICE"] = recognizeSplice;
  tokenRecognizers["REVERSE"] = recognizeReverse;
  tokenRecognizers["SORT"] = recognizeSort;
  tokenRecognizers["FILL"] = recognizeFill;
  tokenRecognizers["JOIN"] = recognizeJoin;
  tokenRecognizers["EVERY"] = recognizeEvery;
  tokenRecognizers["SOME"] = recognizeSome;
  tokenRecognizers["FIND"] = recognizeFind;
  tokenRecognizers["FIND_INDEX"] = recognizeFindIndex;
  tokenRecognizers["FIND_LAST"] = recognizeFindLast;
  tokenRecognizers["FIND_LAST_INDEX"] = recognizeFindLastIndex;
  tokenRecognizers["FILTER"] = recognizeFilter;
  tokenRecognizers["MAP"] = recognizeMap;
  tokenRecognizers["REDUCE"] = recognizeReduce;
  tokenRecognizers["FLAT"] = recognizeFlat;
  tokenRecognizers["FLAT_MAP"] = recognizeFlatMap;
  tokenRecognizers["FOR_EACH"] = recognizeForEach;
  tokenRecognizers["HAS_KEY "] = recognizeHasKey;
  tokenRecognizers["KEYS "] = recognizeKeys;
  tokenRecognizers["VALUES "] = recognizeValues;
  tokenRecognizers["ENTRIES "] = recognizeEntries;
  tokenRecognizers["GET"] = recognizeGet;
  tokenRecognizers["CHAR_AT"] = recognizeCharAt;
  tokenRecognizers["CHAR_CODE_AT"] = recognizeCharCodeAt;
  tokenRecognizers["MATCH"] = recognizeMatch;
  tokenRecognizers["MATCH_ALL"] = recognizeMatchAll;
  tokenRecognizers["PAD_END"] = recognizePadEnd;
  tokenRecognizers["PAD_START"] = recognizePadStart;
  tokenRecognizers["REPEAT"] = recognizeRepeat;
  tokenRecognizers["REPLACE"] = recognizeReplace;
  tokenRecognizers["REPLACE_ALL"] = recognizeReplaceAll;
  tokenRecognizers["SPLIT"] = recognizeSplit;
  tokenRecognizers["STARTS_WITH"] = recognizeStartsWith;
  tokenRecognizers["ENDS_WITH"] = recognizeEndsWith;
  tokenRecognizers["SUBSTRING"] = recognizeSubstring;
  tokenRecognizers["LOWERCASE"] = recognizeLowercase;
  tokenRecognizers["UPPERCASE"] = recognizeUppercase;
  tokenRecognizers["TRIM"] = recognizeTrim;
  tokenRecognizers["TRIM_END"] = recognizeTrimEnd;
  tokenRecognizers["TRIM_START"] = recognizeTrimStart;
}
