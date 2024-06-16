#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "lexer/lexer.hpp"

class Interpreter {
    
public:
    void interpret(const std::string& code);
};

#endif
