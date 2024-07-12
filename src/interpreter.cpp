#include "interpreter.hpp"

std::vector<Token> tokens;

void Interpreter::interpret(const std::string& code) {
  Lexer lexer(code);
  Token previousToken = {TokenType::TOKEN_UNKNOWN, "Unknown", "Initialize interpreter"};

  do {
    std::cout << "###Token###" << std::endl;
    std::cout << "Value: " << previousToken.value << std::endl;
    std::cout << "Desc: " << previousToken.desc << std::endl;
    std::cout << "Position: " << lexer.pos << std::endl;
    std::cout << std::endl;

    switch (previousToken.type) {
      case TokenType::TOKEN_FUNCTION: {
        tokens.push_back(lexer.storeName('f'));
        break;
      }

      case TokenType::TOKEN_VARIABLE: {
        tokens.push_back(lexer.storeName('v'));
        break;
      }

      default: {
        tokens.push_back(lexer.getNextToken());
        break;
      }
    }
    previousToken = getPreviousToken();
  } while (getPreviousToken().type != TokenType::TOKEN_EOF);
}

Token Interpreter::getPreviousToken() { return tokens[tokens.size() - 1]; }
