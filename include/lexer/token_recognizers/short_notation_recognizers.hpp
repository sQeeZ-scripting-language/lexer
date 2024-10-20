#ifndef SHORT_NOTATION_RECOGNIZERS_HPP
#define SHORT_NOTATION_RECOGNIZERS_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = std::function<void(Lexer&, std::unique_ptr<Token>&)>;

void recognizeMap(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFilter(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeReduce(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeConcat(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeZip(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeJoin(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeFind(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeCount(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeSort(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);
void recognizeReverse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);

void registerShortNotationRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif  // SHORT_NOTATION_RECOGNIZERS_HPP
