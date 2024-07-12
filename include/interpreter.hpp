#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lexer/lexer.hpp"
#include "token.hpp"

class Interpreter {
public:
  void interpret(const std::string& code);

private:
  Token getPreviousToken();
};

#endif
