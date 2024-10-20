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

void registerShortNotationRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
