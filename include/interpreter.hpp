#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "lexer/lexer.hpp"

class Interpreter {
public:
  void interpret(const std::string& code);
};

#endif
