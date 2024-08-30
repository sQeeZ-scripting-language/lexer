#include "lexer/token_recognizers/logical_recognizers.hpp"

Token* recognizeEqual(Lexer& lexer) {
  return lexer.checkKeyword("==") ? new Token{LogicalToken::EQUAL, 2, "==", "Equal"} : nullptr;
}

Token* recognizeNotEqual(Lexer& lexer) {
  return lexer.checkKeyword("!=") ? new Token{LogicalToken::NOT_EQUAL, 2, "!=", "Not Equal"} : nullptr;
}

Token* recognizeGreater(Lexer& lexer) {
  return lexer.checkKeyword(">") && !lexer.checkKeyword(">=") && !lexer.checkKeyword(">>")
             ? new Token{LogicalToken::GREATER, 1, ">", "Greater"}
             : nullptr;
}

Token* recognizeLess(Lexer& lexer) {
  return lexer.checkKeyword("<") && !lexer.checkKeyword("<=") && !lexer.checkKeyword("<<") &&
                 !lexer.checkKeyword("<>") && !lexer.checkKeyword("<#>") && !lexer.checkKeyword("<!>")
             ? new Token{LogicalToken::LESS, 1, "<", "Less"}
             : nullptr;
}

Token* recognizeGreaterEqual(Lexer& lexer) {
  return lexer.checkKeyword(">=") ? new Token{LogicalToken::GREATER_EQUAL, 2, ">=", "Greater Equal"} : nullptr;
}

Token* recognizeLessEqual(Lexer& lexer) {
  return lexer.checkKeyword("<=") ? new Token{LogicalToken::LESS_EQUAL, 2, "<=", "Less Equal"} : nullptr;
}

Token* recognizeAnd(Lexer& lexer) {
  return lexer.checkKeyword("&&") ? new Token{LogicalToken::AND, 2, "&&", "And"} : nullptr;
}

Token* recognizeOr(Lexer& lexer) {
  return lexer.checkKeyword("||") ? new Token{LogicalToken::OR, 2, "||", "Or"} : nullptr;
}

Token* recognizeNot(Lexer& lexer) {
  return lexer.checkKeyword("!") && !lexer.checkKeyword("!=") && !lexer.checkKeyword("!!")
             ? new Token{LogicalToken::NOT, 1, "!", "Not"}
             : nullptr;
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
