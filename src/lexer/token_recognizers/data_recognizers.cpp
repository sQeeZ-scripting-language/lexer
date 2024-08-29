#include "lexer/token_recognizers/data_recognizers.hpp"

char getType(std::string identifier) {
  return identifiers.find(identifier) != identifiers.end() ? identifiers[identifier] : '\0';
}

std::string extractIdentifier(Lexer &lexer) {
  lexer.skipWhitespace();
  size_t i = lexer.code.find(' ', lexer.pos);
  return (i == std::string::npos) ? lexer.code.substr(lexer.pos) : lexer.code.substr(lexer.pos, i - lexer.pos);
}

Token storeIdentifier(Lexer &lexer, std::string identifier, char type) {
  lexer.skip(identifier.size());
  if (!isValidIdentifier(identifier)) {
    return {ErrorToken::IDENTIFIER_INVALID_FORMAT, identifier, "Invalid identifier"};
  } else if (isReservedKeyword(identifier)) {
    return {ErrorToken::IDENTIFIER_RESERVED_KEYWORD, identifier, "Reserved keyword"};
  } else if (getType(identifier) == '\0') {
    identifiers[identifier] = type;
    switch (type) {
      case 'F':
        return {DataToken::SET_FUNCTION_IDENTIFIER, identifier, "Function identifier stored"};
      case 'V':
        return {DataToken::SET_VARIABLE_IDENTIFIER, identifier, "Variable identifier stored"};
      case 'C':
        return {DataToken::SET_CONSTANT_IDENTIFIER, identifier, "Constant identifier stored"};
      default:
        return {BasicToken::UNKNOWN, identifier, "Invalid type"};
    }
  } else {
    return {ErrorToken::IDENTIFIER_ALREADY_EXISTS, identifier, "Identifier already exists"};
  }
}

Token recognizeIdentifier(std::string identifier) {
  switch (getType(identifier)) {
    case 'F':
      return {DataToken::USE_FUNCTION_IDENTIFIER, identifier, "Function identifier"};
    case 'V':
      return {DataToken::USE_VARIABLE_IDENTIFIER, identifier, "Variable identifier"};
    case 'C':
      return {DataToken::USE_CONSTANT_IDENTIFIER, identifier, "Constant identifier"};
    default:
      return {ErrorToken::IDENTIFIER_NOT_FOUND, identifier, "Invalid identifier"};
  }
}

bool isValidIdentifier(std::string identifier) {
  std::regex regexPattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
  return std::regex_match(identifier, regexPattern);
}

bool isReservedKeyword(std::string identifier) {
  Lexer lexer(identifier);
  Token token = lexer.getNextToken();
  return token.tag == Token::TypeTag::BASIC && token.type.basicToken == BasicToken::TOKEN_EOF;
}
