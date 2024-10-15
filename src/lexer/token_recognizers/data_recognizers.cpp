#include "lexer/token_recognizers/data_recognizers.hpp"

#include <iostream>

#include "lexer/lexer.hpp"

void DataRecognizer::extractStringLiteral(int pos, const std::string& code, std::unique_ptr<Token>& tokenPtr) {
  std::vector<char> charList;
  bool isClosed = false;
  int position = pos;
  while (position < code.size()) {
    if (code[position] == '"' && (charList.empty() || charList.back() != '\\')) {
      isClosed = true;
      break;
    }
    charList.push_back(code[position]);
    ++position;
  }
  std::string literal(charList.begin(), charList.end());
  tokenPtr = std::make_unique<Token>(DataToken::STRING_LITERAL, static_cast<int>(charList.size()), literal,
                                     "DataToken::STRING_LITERAL", "String Literal");
}

void DataRecognizer::extractCommentLiteral(int pos, const std::string& code, std::unique_ptr<Token>& tokenPtr) {
  std::vector<char> charList;
  bool isClosed = false;
  int position = pos;
  while (position < code.size()) {
    if (code[position] == '\n') {
      isClosed = true;
      break;
    }
    charList.push_back(code[position]);
    ++position;
  }
  std::string literal(charList.begin(), charList.end());
  tokenPtr = std::make_unique<Token>(DataToken::COMMENT_LITERAL, static_cast<int>(charList.size()), literal,
                                     "DataToken::COMMENT_LITERAL", "Comment Literal");
}

void DataRecognizer::getNextToken(std::string nextToken, std::unique_ptr<Token>& tokenPtr) {
  if (isInteger(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::INTEGER_LITERAL, static_cast<int>(nextToken.length()), nextToken,
                                       "DataToken::INTEGER_LITERAL", "Integer Literal");
  } else if (isDouble(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::DOUBLE_LITERAL, static_cast<int>(nextToken.length()), nextToken,
                                       "DataToken::DOUBLE_LITERAL", "Double Literal");
  } else if (isValidIdentifier(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::IDENTIFIER, static_cast<int>(nextToken.length()), nextToken,
                                       "DataToken::IDENTIFIER", "Identifier");
  } else {
    tokenPtr = std::make_unique<Token>(BasicToken::UNKNOWN, static_cast<int>(nextToken.length()), nextToken,
                                       "BasicToken::UNKNOWN", "Unknown Token");
  }
}

bool DataRecognizer::isInteger(std::string value) {
  std::regex pattern(R"(^\d+$)");
  return std::regex_match(value, pattern);
}

bool DataRecognizer::isDouble(std::string value) {
  std::regex pattern(R"(^\d*\.?\d+$)");
  return std::regex_match(value, pattern);
}

bool DataRecognizer::isValidIdentifier(std::string value) {
  std::regex pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
  return std::regex_match(value, pattern);
}
