#include "interpreter.hpp"

void Interpreter::interpret(const std::string& code) {
    Lexer lexer(code);
    Token token;
    do {
        token = lexer.getNextToken();
        std::cout << "Token: " << token.value << std::endl;
    } while (token.type != TokenType::TOKEN_EOF);
}
