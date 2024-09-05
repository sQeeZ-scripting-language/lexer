#ifndef LEXER_HPP
#define LEXER_HPP

#include <cctype>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "lexer/token_recognizers/data_recognizers.hpp"
#include "lexer/tokens/token.hpp"

class Lexer {
public:
  Lexer(const std::string& code);
  std::vector<Token> lex();
  Token* lexSpecialCases(Token previousToken, DataRecognizer& dataRecognizer);
  Token* getNextToken();
  Token* extractStringValue();
  std::string extractToken();
  bool checkKeyword(const std::string& keyword);
  void skip(size_t size);
  void skipWhitespace();
  char advance();
  char peek();
  bool isEOF();

  const std::string code;
  size_t pos;
  std::unordered_map<std::string, Token* (*)(Lexer&)> tokenRecognizers;

private:
  void registerTokenRecognizers();
  void log(Token token);
  std::vector<Token> tokens;
};

#endif
