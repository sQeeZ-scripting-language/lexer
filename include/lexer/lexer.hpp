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
  Token storeName(char type);
  Token getName(char type);
  bool checkKeyword(const std::string& keyword);
  bool checkName(const std::unordered_map<std::string, std::string>& map, const std::string& name);
  void skip(size_t size);

  const std::string code;
  size_t pos;
  std::unordered_map<std::string, Token (*)(Lexer&)> tokenRecognizers;
  std::unordered_map<std::string, std::string> functions;
  std::unordered_map<std::string, std::string> variables;

private:
  void registerTokenRecognizers();
  void skipWhitespace();
  bool isEOF();
  char peek();
  char advance();
};

#endif
