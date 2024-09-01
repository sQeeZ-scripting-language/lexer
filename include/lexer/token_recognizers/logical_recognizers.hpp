#ifndef LOGICAL_RECOGNIZERS_HPP
#define LOGICAL_RECOGNIZERS_HPP

#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = Token* (*)(Lexer&);

Token* recognizeEqual(Lexer& lexer);
Token* recognizeNotEqual(Lexer& lexer);
Token* recognizeGreater(Lexer& lexer);
Token* recognizeLess(Lexer& lexer);
Token* recognizeGreaterEqual(Lexer& lexer);
Token* recognizeLessEqual(Lexer& lexer);
Token* recognizeAnd(Lexer& lexer);
Token* recognizeOr(Lexer& lexer);
Token* recognizeNot(Lexer& lexer);

void registerLogicalRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
