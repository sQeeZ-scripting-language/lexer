#ifndef KEYWORD_RECOGNIZERS_HPP
#define KEYWORD_RECOGNIZERS_HPP

#include <unordered_map>
#include <string>
#include "lexer/lexer.hpp"

using TokenRecognizer = Token (*)(Lexer&);

Token recognizeIfKeyword(Lexer& lexer);
Token recognizeElseKeyword(Lexer& lexer);
Token recognizeElseIfKeyword(Lexer& lexer);
Token recognizeForKeyword(Lexer& lexer);
Token recognizeInKeyword(Lexer& lexer);
Token recognizeBreakKeyword(Lexer& lexer);
Token recognizeContinueKeyword(Lexer& lexer);
Token recognizeReturnKeyword(Lexer& lexer);
Token recognizeFunctionKeyword(Lexer& lexer);
Token recognizeLetKeyword(Lexer& lexer);
Token recognizeConstKeyword(Lexer& lexer);

bool checkIfKeyword(const std::string& keyword, Lexer& lexer);

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
