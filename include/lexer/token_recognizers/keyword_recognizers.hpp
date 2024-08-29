#ifndef KEYWORD_RECOGNIZERS_HPP
#define KEYWORD_RECOGNIZERS_HPP

#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = Token (*)(Lexer&);

Token recognizeVariable(Lexer& lexer);
Token recognizeIf(Lexer& lexer);
Token recognizeElse(Lexer& lexer);
Token recognizeElseIf(Lexer& lexer);
Token recognizeFor(Lexer& lexer);
Token recognizeFunction(Lexer& lexer);
Token recognizeReturn(Lexer& lexer);

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
