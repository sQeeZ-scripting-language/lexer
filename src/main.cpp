#include <iostream>
#include "interpreter.hpp"

int main() {
    Interpreter interpreter;

    std::string code = "print('Hello, world!')";
    interpreter.interpret(code);

    return 0;
}
