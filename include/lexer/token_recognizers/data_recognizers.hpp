#ifndef DATA_RECOGNIZERS_HPP
#define DATA_RECOGNIZERS_HPP

#include <cctype>
#include <regex>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

class DataRecognizer {
public:
  Token *storeIdentifier(Lexer &lexer, char type);
  Token *recognizeIdentifier(Lexer &lexer);
  Token *recognizeString(Lexer &lexer);

  std::unordered_map<std::string, char> identifiers;

private:
  bool isValidIdentifier(std::string identifier);
  bool isReservedKeyword(std::string identifier);
  char getType(std::string identifier);
  std::string extractIdentifier(Lexer &lexer);
};

#endif
