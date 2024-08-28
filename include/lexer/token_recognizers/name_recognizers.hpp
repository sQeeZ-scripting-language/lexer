#ifndef NAME_RECOGNIZERS_HPP
#define NAME_RECOGNIZERS_HPP

#include <cctype>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include "token.hpp"
#include <lexer.hpp>

std::unordered_map<std::string, char> names;

char getType(std::string name);
std::string extractName(Lexer &lexer);
Token storeName(Lexer &lexer, std::string name, char type);
Token recognizeName(std::string name);

#endif
