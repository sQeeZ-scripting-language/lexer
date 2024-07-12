#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class TokenType {
  TOKEN_EOF,
  // Syntax
  TOKEN_SEMICOLON,
  TOKEN_COMMA,
  TOKEN_DOT,
  TOKEN_COLON,
  TOKEN_SINGLE_QUOTE,
  TOKEN_DOUBLE_QUOTE,
  TOKEN_OPEN_PARENTHESIS,
  TOKEN_CLOSE_PARENTHESIS,
  TOKEN_OPEN_BRACKET,
  TOKEN_CLOSE_BRACKET,
  TOKEN_OPEN_BRACE,
  TOKEN_CLOSE_BRACE,
  TOKEN_ARROW,
  TOKEN_HASHTAG,
  // Keywords
  TOKEN_VARIABLE,
  TOKEN_IF,
  TOKEN_ELSE,
  TOKEN_ELSE_IF,
  TOKEN_FOR,
  TOKEN_IN,
  TOKEN_BREAK,
  TOKEN_CONTINUE,
  TOKEN_FUNCTION,
  TOKEN_RETURN,
  // Operators
  TOKEN_ASSIGN,
  TOKEN_ADDITION,
  TOKEN_SUBTRACTION,
  TOKEN_MULTIPLICATION,
  TOKEN_DIVISION,
  TOKEN_MODULUS,
  TOKEN_ADDITION_ASSIGNMENT,
  TOKEN_SUBTRACTION_ASSIGNMENT,
  TOKEN_MULTIPLICATION_ASSIGNMENT,
  TOKEN_DIVISION_ASSIGNMENT,
  TOKEN_MODULUS_ASSIGNMENT,
  TOKEN_INCREMENT,
  TOKEN_DECREMENT,
  TOKEN_POTENTIATION,
  TOKEN_FLOOR_DIVISION,
  // Logical
  TOKEN_EQUAL,
  TOKEN_NOT_EQUAL,
  TOKEN_GREATER,
  TOKEN_LESS,
  TOKEN_GREATER_EQUAL,
  TOKEN_LESS_EQUAL,
  TOKEN_AND,
  TOKEN_OR,
  TOKEN_NOT,
  // Log
  TOKEN_LOG_BASIC,
  TOKEN_LOG_COLORED,
  TOKEN_LOG_ERROR,
  // Data
  TOKEN_FUNCTION_NAME,
  TOKEN_VARIABLE_NAME,
  // Default
  TOKEN_FAILURE,
  TOKEN_UNKNOWN
};

struct Token {
  TokenType type;
  std::string value;
  std::string desc;
};

#endif
