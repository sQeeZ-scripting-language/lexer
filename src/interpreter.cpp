#include "interpreter.hpp"

void Interpreter::interpret(const std::string& code) {
  Lexer lexer(code);
  Token token;
  do {
    token = lexer.getNextToken();
    std::cout << "###Token###" << std::endl;
    std::cout << "Value: " << token.value << std::endl;
    std::cout << "Desc: " << token.desc << std::endl;
    std::cout << std::endl;

  } while (token.type != TokenType::TOKEN_EOF);
}
