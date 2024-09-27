#include "lexer/token_recognizers/data_recognizers.hpp"

#include <iostream>

#include "lexer/lexer.hpp"

void DataRecognizer::storeIdentifier(std::string identifier, char type, std::unique_ptr<Token>& tokenPtr) {
  if (!isValidIdentifier(identifier)) {
    tokenPtr =
        std::make_unique<Token>(ErrorToken::IDENTIFIER_INVALID_FORMAT, static_cast<int>(identifier.length()),
                                identifier, "ErrorToken::IDENTIFIER_INVALID_FORMAT", "Invalid identifier format");
  } else if (isReservedKeyword(identifier)) {
    tokenPtr = std::make_unique<Token>(ErrorToken::IDENTIFIER_RESERVED_KEYWORD, static_cast<int>(identifier.length()),
                                       identifier, "ErrorToken::IDENTIFIER_RESERVED_KEYWORD", "Reserved keyword");
  } else if (getType(identifier) == '\0') {
    identifiers[identifier] = type;
    switch (type) {
      case 'F':
        tokenPtr =
            std::make_unique<Token>(DataToken::SET_FUNCTION_IDENTIFIER, static_cast<int>(identifier.length()),
                                    identifier, "DataToken::SET_FUNCTION_IDENTIFIER", "Function identifier stored");
        break;
      case 'V':
        tokenPtr =
            std::make_unique<Token>(DataToken::SET_VARIABLE_IDENTIFIER, static_cast<int>(identifier.length()),
                                    identifier, "DataToken::SET_VARIABLE_IDENTIFIER", "Variable identifier stored");
        break;
      case 'C':
        tokenPtr =
            std::make_unique<Token>(DataToken::SET_CONSTANT_IDENTIFIER, static_cast<int>(identifier.length()),
                                    identifier, "DataToken::SET_CONSTANT_IDENTIFIER", "Constant identifier stored");
        break;
      default:
        tokenPtr = std::make_unique<Token>(ErrorToken::IDENTIFIER_INVALID_TYPE, 0, identifier,
                                           "ErrorToken::IDENTIFIER_INVALID_TYPE", "Invalid Identifier type");
    }
  } else {
    tokenPtr =
        std::make_unique<Token>(ErrorToken::IDENTIFIER_ALREADY_EXISTS, static_cast<int>(identifier.length()),
                                identifier, "ErrorToken::IDENTIFIER_ALREADY_EXISTS", "Identifier already exists");
  }
}

void DataRecognizer::recognizeIdentifier(std::string identifier, std::unique_ptr<Token>& tokenPtr) {
  switch (getType(identifier)) {
    case 'F':
      tokenPtr = std::make_unique<Token>(DataToken::USE_FUNCTION_IDENTIFIER, static_cast<int>(identifier.length()),
                                         identifier, "DataToken::USE_FUNCTION_IDENTIFIER", "Function identifier");
      break;
    case 'V':
      tokenPtr = std::make_unique<Token>(DataToken::USE_VARIABLE_IDENTIFIER, static_cast<int>(identifier.length()),
                                         identifier, "DataToken::USE_VARIABLE_IDENTIFIER", "Variable identifier");
      break;
    case 'C':
      tokenPtr = std::make_unique<Token>(DataToken::USE_CONSTANT_IDENTIFIER, static_cast<int>(identifier.length()),
                                         identifier, "DataToken::USE_CONSTANT_IDENTIFIER", "Constant identifier");
      break;
    default:
      tokenPtr = std::make_unique<Token>(ErrorToken::IDENTIFIER_NOT_FOUND, static_cast<int>(identifier.length()),
                                         identifier, "ErrorToken::IDENTIFIER_NOT_FOUND", "Invalid identifier");
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

bool DataRecognizer::isReservedKeyword(std::string identifier) {
  Lexer lexer(identifier);
  std::unique_ptr<Token> tokenPtr;
  lexer.getNextToken(tokenPtr);
  return tokenPtr != nullptr;
}

char DataRecognizer::getType(std::string identifier) {
  return identifiers.find(identifier) != identifiers.end() ? identifiers[identifier] : '\0';
}
