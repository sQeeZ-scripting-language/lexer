#ifndef MAIN_HPP
#define MAIN_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lexer/lexer.hpp"
#include "lexer/token_recognizers/data_recognizers.hpp"

class LexerMain {
public:
  std::vector<Token> lex(const std::string& code);

private:
  void logToken(Token token);
};

std::vector<Token> tokens;

#endif
