#ifndef SHORT_NOTATION_RECOGNIZERS_HPP
#define SHORT_NOTATION_RECOGNIZERS_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = std::function<void(Lexer&, std::unique_ptr<Token>&)>;

void recognizeLength(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeConcat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeIncludes(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeIndexOf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeLastIndexOf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeSlice(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizePush(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizePop(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeShift(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeUnshift(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeSplice(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeReverse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeSort(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFill(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeJoin(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeCount(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeEvery(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeSome(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFind(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFindIndex(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFindLast(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFindLastIndex(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFilter(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeReduce(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFlat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFlatMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeForEach(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeHasKey(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeKeys(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeValues(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeEntries(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeGet(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeCharAt(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeCharCodeAt(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeMatch(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeMatchAll(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizePadEnd(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizePadStart(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeRepeat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeReplace(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeReplaceAll(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeSplit(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeStartsWith(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeEndsWith(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeSubstring(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeLowercase(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeUppercase(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeTrim(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeTrimEnd(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeTrimStart(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);

void registerShortNotationRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif  // SHORT_NOTATION_RECOGNIZERS_HPP
