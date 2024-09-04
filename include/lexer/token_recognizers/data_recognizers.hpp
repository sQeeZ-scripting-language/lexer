#ifndef DATA_RECOGNIZERS_HPP
#define DATA_RECOGNIZERS_HPP

#include <cctype>
#include <regex>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "lexer/tokens/token.hpp"

class DataRecognizer {
public:
  Token *storeIdentifier(std::string identifier, char type);
  Token *recognizeIdentifier(std::string identifier);
  Token *recognizeNumericValue(std::string number);

  std::unordered_map<std::string, char> identifiers;

private:
  bool isValidIdentifier(std::string identifier);
  bool isReservedKeyword(std::string identifier);
  char getType(std::string identifier);
};

#endif
