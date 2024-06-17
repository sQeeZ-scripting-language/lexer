#ifndef LOG_RECOGNIZERS_HPP
#define LOG_RECOGNIZERS_HPP

#include <unordered_map>
#include <string>
#include "lexer/lexer.hpp"

using TokenRecognizer = Token (*)(Lexer&);

Token recognizeColoredLog(Lexer& lexer);
Token recognizeBasicLog(Lexer& lexer);
Token recognizeErrorLog(Lexer& lexer);

bool checkIfLogKeyword(const std::string& keyword, Lexer& lexer);

void registerLogRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
