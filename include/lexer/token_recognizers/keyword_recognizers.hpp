#ifndef KEYWORD_RECOGNIZERS_HPP
#define KEYWORD_RECOGNIZERS_HPP

#include <unordered_map>
#include <string>
#include "lexer/lexer.hpp"

using TokenRecognizer = Token (*)(Lexer&);

Token recognizeIfKeyword(Lexer& lexer);
Token recognizeElseKeyword(Lexer& lexer);
void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
