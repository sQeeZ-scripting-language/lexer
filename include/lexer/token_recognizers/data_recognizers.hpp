#ifndef DATA_RECOGNIZERS_HPP
#define DATA_RECOGNIZERS_HPP

#include <cctype>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "lexer/tokens/token.hpp"

class DataRecognizer {
public:
  void getNextToken(std::string nextToken, std::unique_ptr<Token>& tokenPtr);

private:
  bool isInteger(std::string value);
  bool isDouble(std::string value);
  bool isValidIdentifier(std::string value);
};

#endif
