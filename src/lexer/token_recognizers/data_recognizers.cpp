#include "lexer/token_recognizers/data_recognizers.hpp"

#include <iostream>

#include "lexer/lexer.hpp"

void DataRecognizer::recognizeIdentifier(std::string identifier, std::unique_ptr<Token>& tokenPtr) {
  if (isValidIdentifier(identifier)) {
    tokenPtr = std::make_unique<Token>(DataToken::IDENTIFIER, static_cast<int>(identifier.length()), identifier,
                                       "DataToken::IDENTIFIER", "Identifier");
  }
}

void DataRecognizer::recognizeNumericLiteral(std::string number, std::unique_ptr<Token>& tokenPtr) {
  std::regex integerPattern(R"(^\d+$)");
  std::regex doublePattern(R"(^\d*\.?\d+$)");
  if (std::regex_match(number, integerPattern)) {
    tokenPtr = std::make_unique<Token>(DataToken::INTEGER_LITERAL, static_cast<int>(number.length()), number,
                                       "DataToken::INTEGER_LITERAL", "Integer Literal");
  } else if (std::regex_match(number, doublePattern)) {
    tokenPtr = std::make_unique<Token>(DataToken::DOUBLE_LITERAL, static_cast<int>(number.length()), number,
                                       "DataToken::DOUBLE_LITERAL", "Double Literal");
  }
}

bool DataRecognizer::isValidIdentifier(std::string identifier) {
  std::regex regexPattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
  return std::regex_match(identifier, regexPattern);
}
