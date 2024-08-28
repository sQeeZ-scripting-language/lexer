#ifndef LEXER_HPP
#define LEXER_HPP

#include <cctype>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include "token.hpp"

class Lexer {
public:
  Lexer(const std::string& code);
  Token getNextToken();
  bool checkKeyword(const std::string& keyword);
  void skip(size_t size);
  void skipWhitespace();

  const std::string code;
  size_t pos;
  std::unordered_map<std::string, Token (*)(Lexer&)> tokenRecognizers;

private:
  void registerTokenRecognizers();
  bool isEOF();
  char peek();
  char advance();
};

#endif
