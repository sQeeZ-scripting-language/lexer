#include "lexer/token_recognizers/data_recognizers.hpp"

#include <iostream>

bool DataRecognizer::isValidIdentifier(std::string identifier) {
  std::regex regexPattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
  return std::regex_match(identifier, regexPattern);
}

bool DataRecognizer::isReservedKeyword(std::string identifier) {
  Lexer lexer(identifier);
  Token token = lexer.getNextToken();
  return token.tag == Token::TypeTag::BASIC && token.type.basicToken == BasicToken::TOKEN_EOF;
}

char DataRecognizer::getType(std::string identifier) {
  return identifiers.find(identifier) != identifiers.end() ? identifiers[identifier] : '\0';
}

std::string DataRecognizer::extractIdentifier(Lexer &lexer) {
  lexer.skipWhitespace();
  size_t i = lexer.code.find(' ', lexer.pos);
  return (i == std::string::npos) ? lexer.code.substr(lexer.pos) : lexer.code.substr(lexer.pos, i - lexer.pos);
}

Token DataRecognizer::storeIdentifier(Lexer &lexer, std::string identifier, char type) {
  lexer.skip(identifier.size());
  if (!isValidIdentifier(identifier)) {
    return {ErrorToken::IDENTIFIER_INVALID_FORMAT, static_cast<int>(identifier.length()), identifier,
            "Invalid identifier"};
  } else if (isReservedKeyword(identifier)) {
    return {ErrorToken::IDENTIFIER_RESERVED_KEYWORD, static_cast<int>(identifier.length()), identifier,
            "Reserved keyword"};
  } else if (getType(identifier) == '\0') {
    identifiers[identifier] = type;
    switch (type) {
      case 'F':
        return {DataToken::SET_FUNCTION_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
                "Function identifier stored"};
      case 'V':
        return {DataToken::SET_VARIABLE_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
                "Variable identifier stored"};
      case 'C':
        return {DataToken::SET_CONSTANT_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
                "Constant identifier stored"};
      default:
        return {BasicToken::UNKNOWN, 0, identifier, "Invalid type"};
    }
  } else {
    return {ErrorToken::IDENTIFIER_ALREADY_EXISTS, static_cast<int>(identifier.length()), identifier,
            "Identifier already exists"};
  }
}

Token DataRecognizer::recognizeIdentifier(std::string identifier) {
  switch (getType(identifier)) {
    case 'F':
      return {DataToken::USE_FUNCTION_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
              "Function identifier"};
    case 'V':
      return {DataToken::USE_VARIABLE_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
              "Variable identifier"};
    case 'C':
      return {DataToken::USE_CONSTANT_IDENTIFIER, static_cast<int>(identifier.length()), identifier,
              "Constant identifier"};
    default:
      return {ErrorToken::IDENTIFIER_NOT_FOUND, static_cast<int>(identifier.length()), identifier,
              "Invalid identifier"};
  }
}

Token* DataRecognizer::recognizeString(Lexer &lexer) {
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
