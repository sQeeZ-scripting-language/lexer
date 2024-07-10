#include "lexer/token_recognizers/logical_recognizers.hpp"

Token recognizeEqual(Lexer& lexer) {
  if (lexer.checkKeyword("==")) {
    lexer.skip(2);
    return {TokenType::TOKEN_EQUAL, "==", "Equal"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeNotEqual(Lexer& lexer) {
  if (lexer.checkKeyword("!=")) {
    lexer.skip(2);
    return {TokenType::TOKEN_NOT_EQUAL, "!=", "Not Equal"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeGreater(Lexer& lexer) {
  if (lexer.checkKeyword(">") && !lexer.checkKeyword(">=") && !lexer.checkKeyword(">>")) {
    lexer.skip(1);
    return {TokenType::TOKEN_GREATER, ">", "Greater"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeLess(Lexer& lexer) {
  if (lexer.checkKeyword("<") && !lexer.checkKeyword("<=") && !lexer.checkKeyword("<<")) {
    lexer.skip(1);
    return {TokenType::TOKEN_LESS, "<", "Less"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeGreaterEqual(Lexer& lexer) {
  if (lexer.checkKeyword(">=")) {
    lexer.skip(2);
    return {TokenType::TOKEN_GREATER_EQUAL, ">=", "Greater Equal"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeLessEqual(Lexer& lexer) {
  if (lexer.checkKeyword("<=")) {
    lexer.skip(2);
    return {TokenType::TOKEN_LESS_EQUAL, "<=", "Less Equal"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeAnd(Lexer& lexer) {
  if (lexer.checkKeyword("&&")) {
    lexer.skip(2);
    return {TokenType::TOKEN_AND, "&&", "And"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeOr(Lexer& lexer) {
  if (lexer.checkKeyword("||")) {
    lexer.skip(2);
    return {TokenType::TOKEN_OR, "||", "Or"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeNot(Lexer& lexer) {
  if (lexer.checkKeyword("!") && !lexer.checkKeyword("!=") && !lexer.checkKeyword("!!")) {
    lexer.skip(1);
    return {TokenType::TOKEN_NOT, "!", "Not"};
  }
  return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

void registerLogicalRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["=="] = recognizeEqual;
  tokenRecognizers["!="] = recognizeNotEqual;
  tokenRecognizers[">"] = recognizeGreater;
  tokenRecognizers["<"] = recognizeLess;
  tokenRecognizers[">="] = recognizeGreaterEqual;
  tokenRecognizers["<="] = recognizeLessEqual;
  tokenRecognizers["&&"] = recognizeAnd;
  tokenRecognizers["||"] = recognizeOr;
  tokenRecognizers["!"] = recognizeNot;
}
