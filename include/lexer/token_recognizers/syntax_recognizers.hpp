#ifndef SYNTAX_RECOGNIZERS_HPP
#define SYNTAX_RECOGNIZERS_HPP

#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = Token (*)(Lexer&);

Token recognizeSemicolon(Lexer& lexer);
Token recognizeComma(Lexer& lexer);
Token recognizeDot(Lexer& lexer);
Token recognizeColon(Lexer& lexer);
Token recognizeSingleQuote(Lexer& lexer);
Token recognizeDoubleQuote(Lexer& lexer);
Token recognizeOpenParenthesis(Lexer& lexer);
Token recognizeCloseParenthesis(Lexer& lexer);
Token recognizeOpenBracket(Lexer& lexer);
Token recognizeCloseBracket(Lexer& lexer);
Token recognizeOpenBrace(Lexer& lexer);
Token recognizeCloseBrace(Lexer& lexer);
Token recognizeArrow(Lexer& lexer);
Token recognizeHashtag(Lexer& lexer);

void registerSyntaxRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif