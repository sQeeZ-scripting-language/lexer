#include "lexer/token_recognizers/data_recognizers.hpp"

#include <iostream>

Token* DataRecognizer::storeIdentifier(Lexer &lexer, char type) {
  std::string identifier = extractToken(lexer);
  if (!isValidIdentifier(identifier)) {
    return new Token{ErrorToken::IDENTIFIER_INVALID_FORMAT, static_cast<int>(identifier.length()), identifier,
            "Invalid identifier format"};
  } else if (isReservedKeyword(identifier)) {
    return new Token{ErrorToken::IDENTIFIER_RESERVED_KEYWORD, static_cast<int>(identifier.length()), identifier,
            "Reserved keyword"};
  } else if (getType(identifier) == '\0') {
    identifiers[identifier] = type;
    switch (type) {
      case 'F':
        return new Token{DataToken::SET_FUNCTION_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
                "Function identifier stored"};
      case 'V':
        return new Token{DataToken::SET_VARIABLE_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
                "Variable identifier stored"};
      case 'C':
        return new Token{DataToken::SET_CONSTANT_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
                "Constant identifier stored"};
      default:
        return new Token{BasicToken::UNKNOWN, 0, identifier, "Invalid type"};
    }
  } else {
    return new Token{ErrorToken::IDENTIFIER_ALREADY_EXISTS, static_cast<int>(identifier.length()), identifier,
            "Identifier already exists"};
  }
}

Token* DataRecognizer::recognizeIdentifier(Lexer &lexer) {
  std::string identifier = extractToken(lexer);
  switch (getType(identifier)) {
    case 'F':
      return new Token{DataToken::USE_FUNCTION_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
              "Function identifier"};
    case 'V':
      return new Token{DataToken::USE_VARIABLE_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
              "Variable identifier"};
    case 'C':
      return new Token{DataToken::USE_CONSTANT_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
              "Constant identifier"};
    default:
      return new Token{ErrorToken::IDENTIFIER_NOT_FOUND, static_cast<int>(identifier.length()), identifier,
              "Invalid identifier"};
  }
}

Token *DataRecognizer::recognizeString(Lexer &lexer) {
  std::vector<char> charList;
  bool isClosed = false;
  while (!lexer.isEOF()) {
    char current = lexer.peek();
    if (current == '"' && (charList.empty() || charList.back() != '\\')) {
      isClosed = true;
      break;
    }
    charList.push_back(current);
    lexer.skip(1);
  }
  std::string value(charList.begin(), charList.end());
  return new Token{DataToken::STRING_VALUE, static_cast<int>(charList.size()), value, "String Value"};
}

Token *DataRecognizer::recognizeNumericValue(Lexer &lexer) {
  std::string number = extractToken(lexer);
  std::regex integerPattern(R"(^\d+$)");
  std::regex doublePattern(R"(^\d*\.?\d+$)");
  if (std::regex_match(number, integerPattern)) {
    return new Token{DataToken::INTEGER_VALUE, static_cast<int>(number.length()), number, "Integer Value"};
  } else if (std::regex_match(number, doublePattern)) {
    return new Token{DataToken::DOUBLE_VALUE, static_cast<int>(number.length()), number, "Double Value"};
  }
  return nullptr;
}

std::string DataRecognizer::extractToken(Lexer &lexer) {  
  lexer.skipWhitespace();
  size_t i = lexer.code.find_first_of(' ', lexer.pos);
  return (i == std::string::npos) ? lexer.code.substr(lexer.pos) : lexer.code.substr(lexer.pos, i - lexer.pos);
}

bool DataRecognizer::isValidIdentifier(std::string identifier) {
  std::regex regexPattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
  return std::regex_match(identifier, regexPattern);
}

bool DataRecognizer::isReservedKeyword(std::string identifier) {
  Lexer lexer(identifier);
  Token* token = lexer.getNextToken();
  return token != nullptr;
}

char DataRecognizer::getType(std::string identifier) {
  return identifiers.find(identifier) != identifiers.end() ? identifiers[identifier] : '\0';
}

