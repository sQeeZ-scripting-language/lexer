#ifndef DATA_RECOGNIZERS_HPP
#define DATA_RECOGNIZERS_HPP

#include <cctype>
#include <regex>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "lexer.hpp"

std::unordered_map<std::string, char> identifiers;

char getType(std::string identifier);
std::string extractIdentifier(Lexer &lexer);
Token storeIdentifier(Lexer &lexer, std::string identifier, char type);
Token recognizeIdentifier(std::string identifier);
bool isValidIdentifier(std::string identifier);
bool isReservedKeyword(std::string identifier);

#endif
