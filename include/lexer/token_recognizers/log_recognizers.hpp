#ifndef LOG_RECOGNIZERS_HPP
#define LOG_RECOGNIZERS_HPP

#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = Token* (*)(Lexer&);

Token* recognizeColoredLog(Lexer& lexer);
Token* recognizeBasicLog(Lexer& lexer);
Token* recognizeErrorLog(Lexer& lexer);
Token* recognizeWarnLog(Lexer& lexer);

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
