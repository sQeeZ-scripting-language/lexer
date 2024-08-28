#include "lexer/token_recognizers/name_recognizers.hpp"

char getType(std::string name) {
    return names.find(name) != names.end() ? names[name] : '\0';
}

std::string extractName(Lexer &lexer) {
  lexer.skipWhitespace();
  size_t i = lexer.code.find(' ', lexer.pos);
  return (i == std::string::npos) ? lexer.code.substr(lexer.pos) : lexer.code.substr(lexer.pos, i - lexer.pos);
}

Token storeName(Lexer &lexer, std::string name, char type) {
    lexer.skip(name.size());
    if (getType(name) == '\0') {
        names[name] = type;
        switch (type) {
        case 'F':
            return {TokenType::TOKEN_FUNCTION_NAME, name, "Function name stored"};

        case 'V':
            return {TokenType::TOKEN_VARIABLE_NAME, name, "Variable name stored"};
        
        default:
            return {TokenType::TOKEN_FAILURE, name, "Invalid type"};
        }
    } else {
        return {TokenType::TOKEN_FAILURE, name, "Name already exists"};
    }
}

Token recognizeName(std::string name) {
    switch (getType(name)) {
    case 'F':
        return {TokenType::TOKEN_FUNCTION_NAME, name, "Function name"};
    case 'V':
        return {TokenType::TOKEN_VARIABLE_NAME, name, "Variable name"};
    default:
        return {TokenType::TOKEN_FAILURE, name, "Invalid name"};
    }
}
