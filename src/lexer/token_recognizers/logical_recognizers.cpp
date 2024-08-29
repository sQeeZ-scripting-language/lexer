#include "lexer/token_recognizers/logical_recognizers.hpp"

Token recognizeEqual(Lexer& lexer) {
  if (lexer.checkKeyword("==")) {
    lexer.skip(2);
    return {LogicalToken::EQUAL, "==", "Equal"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeNotEqual(Lexer& lexer) {
  if (lexer.checkKeyword("!=")) {
    lexer.skip(2);
    return {LogicalToken::NOT_EQUAL, "!=", "Not Equal"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeGreater(Lexer& lexer) {
  if (lexer.checkKeyword(">") && !lexer.checkKeyword(">=") && !lexer.checkKeyword(">>")) {
    lexer.skip(1);
    return {LogicalToken::GREATER, ">", "Greater"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeLess(Lexer& lexer) {
  if (lexer.checkKeyword("<") && !lexer.checkKeyword("<=") && !lexer.checkKeyword("<<") && !lexer.checkKeyword("<>") &&
      !lexer.checkKeyword("<#>") && !lexer.checkKeyword("<!>")) {
    lexer.skip(1);
    return {LogicalToken::LESS, "<", "Less"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeGreaterEqual(Lexer& lexer) {
  if (lexer.checkKeyword(">=")) {
    lexer.skip(2);
    return {LogicalToken::GREATER_EQUAL, ">=", "Greater Equal"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeLessEqual(Lexer& lexer) {
  if (lexer.checkKeyword("<=")) {
    lexer.skip(2);
    return {LogicalToken::LESS_EQUAL, "<=", "Less Equal"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeAnd(Lexer& lexer) {
  if (lexer.checkKeyword("&&")) {
    lexer.skip(2);
    return {LogicalToken::AND, "&&", "And"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeOr(Lexer& lexer) {
  if (lexer.checkKeyword("||")) {
    lexer.skip(2);
    return {LogicalToken::OR, "||", "Or"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeNot(Lexer& lexer) {
  if (lexer.checkKeyword("!") && !lexer.checkKeyword("!=") && !lexer.checkKeyword("!!")) {
    lexer.skip(1);
    return {LogicalToken::NOT, "!", "Not"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
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
