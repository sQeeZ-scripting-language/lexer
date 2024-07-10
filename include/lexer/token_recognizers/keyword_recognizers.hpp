#ifndef KEYWORD_RECOGNIZERS_HPP
#define KEYWORD_RECOGNIZERS_HPP

#include <unordered_map>
#include <string>
#include "lexer/lexer.hpp"

using TokenRecognizer = Token (*)(Lexer&);

Token recognizeVariableDeclaration(Lexer& lexer);
Token recognizeIf(Lexer& lexer);
Token recognizeElse(Lexer& lexer);
Token recognizeElseIf(Lexer& lexer);
Token recognizeFor(Lexer& lexer);
Token recognizeBreak(Lexer& lexer);
Token recognizeContinue(Lexer& lexer);
Token recognizeFunction(Lexer& lexer);
Token recognizeReturn(Lexer& lexer);

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
