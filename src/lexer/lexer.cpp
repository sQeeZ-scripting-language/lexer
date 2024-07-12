#include "lexer/lexer.hpp"

#include "lexer/token_recognizers/keyword_recognizers.hpp"
#include "lexer/token_recognizers/log_recognizers.hpp"
#include "lexer/token_recognizers/logical_recognizers.hpp"
#include "lexer/token_recognizers/operator_recognizers.hpp"
#include "lexer/token_recognizers/syntax_recognizers.hpp"

Lexer::Lexer(const std::string& code) : code(code), pos(0), functions(), variables() { registerTokenRecognizers(); }

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
    if (token.type != TokenType::TOKEN_UNKNOWN) return token;
    pos = originalPosition;
  }

  char currentChar = peek();
  advance();
  return {TokenType::TOKEN_UNKNOWN, std::string(1, currentChar), "Unknown"};
}

Token Lexer::storeName(char type) {
  skipWhitespace();
  size_t i = code.find(' ', pos);
  std::string name = (i == std::string::npos) ? code.substr(pos, i - pos) : code.substr(pos);
  switch (type) {
    case 'f':
      if (functions.find(name) != functions.end()) {
        return Token{TokenType::TOKEN_FAILURE, name, "Function name already exists"};
      } else {
        functions[name] = name;
        return Token{TokenType::TOKEN_FUNCTION_NAME, name, "Function name"};
      }

    case 'v':
      if (variables.find(name) != variables.end()) {
        return Token{TokenType::TOKEN_FAILURE, name, "Variable name already exists"};
      } else {
        variables[name] = name;
        return Token{TokenType::TOKEN_VARIABLE_NAME, name, "Variable name"};
      }

    default:
      throw std::runtime_error("Invalid type");
  }
}

Token Lexer::getName(char type) {
  skipWhitespace();
  size_t i = code.find(' ', pos);
  std::string name = (i == std::string::npos) ? code.substr(pos, i - pos) : code.substr(pos);
  switch (type) {
    case 'f':
      bool isFn = checkName(functions, name);
      return {isFn ? TokenType::TOKEN_FUNCTION_NAME : TokenType::TOKEN_FAILURE, name,
              isFn ? "Function name" : "Invalid function name"};

    case 'v':
      bool isVar = checkName(variables, name);
      return {isVar ? TokenType::TOKEN_VARIABLE_NAME : TokenType::TOKEN_FAILURE, name,
              isVar ? "Variable name" : "Invalid variable name"};

    default:
      throw std::runtime_error("Invalid type");
  }
}

bool Lexer::checkKeyword(const std::string& keyword) { return code.substr(pos, keyword.size()) == keyword; }

bool Lexer::checkName(const std::unordered_map<std::string, std::string>& map, const std::string& name) {
  return map.find(name) != map.end();
}

void Lexer::skip(size_t size) { pos += size; }

bool Lexer::isEOF() { return pos >= code.size(); }

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

void Lexer::skipWhitespace() {
  while (!isEOF() && std::isspace(peek())) {
    advance();
  }
}
