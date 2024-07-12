#include "interpreter.hpp"

std::vector<Token> tokens;

void Interpreter::interpret(const std::string& code) {
  Lexer lexer(code);
  do {
    switch (getPreviousToken().type) {
    case TokenType::TOKEN_FUNCTION:
      // store function name
      break;

    case TokenType::TOKEN_VARIABLE:
      // store variable name
      break;

    default:
      tokens.push_back(lexer.getNextToken());
      break;
    }
    
  } while (getPreviousToken().type != TokenType::TOKEN_EOF);
}

Token Interpreter::getPreviousToken() {
  return tokens[tokens.size() - 1];
}
