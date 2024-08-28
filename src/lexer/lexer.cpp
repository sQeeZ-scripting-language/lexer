#include "lexer/lexer.hpp"

#include "lexer/token_recognizers/keyword_recognizers.hpp"
#include "lexer/token_recognizers/log_recognizers.hpp"
#include "lexer/token_recognizers/logical_recognizers.hpp"
#include "lexer/token_recognizers/operator_recognizers.hpp"
#include "lexer/token_recognizers/syntax_recognizers.hpp"

Lexer::Lexer(const std::string& code) : code(code), pos(0) {
  registerTokenRecognizers();
}

void Lexer::registerTokenRecognizers() {
  registerSyntaxRecognizers(tokenRecognizers);
  registerKeywordRecognizers(tokenRecognizers);
  registerOperatorRecognizers(tokenRecognizers);
  registerLogicalRecognizers(tokenRecognizers);
  registerLogRecognizers(tokenRecognizers);
}

Token Lexer::getNextToken() {
  skipWhitespace();
  if (isEOF()) {
    return {TokenType::TOKEN_EOF, "EOF", "The end of the file"};
  }

  for (const auto& recognizer : tokenRecognizers) {
    size_t originalPosition = pos;
    Token token = recognizer.second(*this);
    if (token.type != TokenType::TOKEN_UNKNOWN) {
      return token;
    }
    pos = originalPosition;
  }
  
  char currentChar = peek();
  advance();
  return {TokenType::TOKEN_UNKNOWN, std::string(1, currentChar), "Unknown"};
}

bool Lexer::checkKeyword(const std::string& keyword) {
  return code.substr(pos, keyword.size()) == keyword; 
}

void Lexer::skip(size_t size) {
  pos += size;
}

void Lexer::skipWhitespace() {
  while (!isEOF() && std::isspace(peek())) {
    advance();
  }
}

bool Lexer::isEOF() { 
  return pos >= code.size();
}

char Lexer::peek() {
  if (isEOF()) {
    return '\0';
  }
  return code[pos];
}

char Lexer::advance() {
  if (!isEOF()) {
    pos++;
  }
  return peek();
}
