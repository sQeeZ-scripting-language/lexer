#include "lexer/token_recognizers/data_recognizers.hpp"

#include <iostream>

#include "lexer/lexer.hpp"

void DataRecognizer::extractStringLiteral(size_t pos, const std::string& code, std::unique_ptr<Token>& tokenPtr) {
  std::vector<char> charList;
  bool isClosed = false;
  size_t position = pos;
  while (position < code.size()) {
    if (code[position] == '"' && (charList.empty() || charList.back() != '\\')) {
      isClosed = true;
      break;
    }
    charList.push_back(code[position]);
    ++position;
  }
  std::string literal(charList.begin(), charList.end());
  tokenPtr = std::make_unique<Token>(DataToken::STRING_LITERAL, charList.size(), pos, literal,
                                     "DataToken::STRING_LITERAL", "String Literal");
}

void DataRecognizer::extractCharLiteral(size_t pos, const std::string& code, std::unique_ptr<Token>& tokenPtr) {
  std::vector<char> charList;
  bool isClosed = false;
  size_t position = pos;
  while (position < code.size()) {
    if (code[position] == '\'' && (charList.empty() || charList.back() != '\\')) {
      isClosed = true;
      break;
    }
    charList.push_back(code[position]);
    ++position;
  }
  std::string literal(charList.begin(), charList.end());
  tokenPtr = std::make_unique<Token>(DataToken::CHAR_LITERAL, charList.size(), pos, literal, "DataToken::CHAR_LITERAL",
                                     "Character Literal");
}

void DataRecognizer::extractCommentLiteral(size_t pos, const std::string& code, std::unique_ptr<Token>& tokenPtr) {
  std::vector<char> charList;
  bool isClosed = false;
  size_t position = pos;
  while (position < code.size()) {
    if (code[position] == '\n') {
      isClosed = true;
      break;
    }
    charList.push_back(code[position]);
    ++position;
  }
  std::string literal(charList.begin(), charList.end());
  tokenPtr = std::make_unique<Token>(DataToken::COMMENT_LITERAL, charList.size(), pos, literal,
                                     "DataToken::COMMENT_LITERAL", "Comment Literal");
}

void DataRecognizer::extractHexCodeLiteral(std::string nextToken, size_t pos, const std::string& code,
                                           std::unique_ptr<Token>& tokenPtr) {
  std::regex pattern(R"(^(?:[0-9a-fA-F]{3}){1,2}$)");
  if (std::regex_match(nextToken, pattern)) {
    tokenPtr = std::make_unique<Token>(DataToken::HEX_CODE_LITERAL, nextToken.length(), pos, nextToken,
                                       "DataToken::HEX_CODE_LITERAL", "Hex Code Literal");
  }
}

void DataRecognizer::getNextToken(size_t pos, std::string nextToken, std::unique_ptr<Token>& tokenPtr) {
  if (isInteger(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::INTEGER_LITERAL, nextToken.length(), pos, nextToken,
                                       "DataToken::INTEGER_LITERAL", "Integer Literal");
  } else if (isDouble(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::DOUBLE_LITERAL, nextToken.length(), pos, nextToken,
                                       "DataToken::DOUBLE_LITERAL", "Double Literal");
  } else if (isBoolean(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::BOOLEAN_LITERAL, nextToken.length(), pos, nextToken,
                                       "DataToken::BOOLEAN_LITERAL", "Boolean Literal");
  } else if (isNull(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::NULL_LITERAL, nextToken.length(), pos, nextToken,
                                       "DataToken::NULL_LITERAL", "Null Literal");
  } else if (isValidIdentifier(nextToken)) {
    tokenPtr = std::make_unique<Token>(DataToken::IDENTIFIER, nextToken.length(), pos, nextToken,
                                       "DataToken::IDENTIFIER", "Identifier");
  } else {
    tokenPtr = std::make_unique<Token>(BasicToken::UNKNOWN, nextToken.length(), pos, nextToken, "BasicToken::UNKNOWN",
                                       "Unknown Token");
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

bool DataRecognizer::isBoolean(std::string value) {
  std::regex pattern(R"(^true|false$)");
  return std::regex_match(value, pattern);
}

bool DataRecognizer::isNull(std::string value) {
  std::regex pattern(R"(^null$)");
  return std::regex_match(value, pattern);
}

bool DataRecognizer::isValidIdentifier(std::string value) {
  std::regex pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
  return std::regex_match(value, pattern);
}
