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
  void extractStringLiteral(size_t pos, const std::string& code, std::unique_ptr<Token>& tokenPtr);
  void extractCommentLiteral(size_t pos, const std::string& code, std::unique_ptr<Token>& tokenPtr);
  void getNextToken(size_t pos, std::string nextToken, std::unique_ptr<Token>& tokenPtr);

private:
  bool isInteger(std::string value);
  bool isDouble(std::string value);
  bool isValidIdentifier(std::string value);
};

#endif
