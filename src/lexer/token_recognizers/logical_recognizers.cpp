#include "lexer/token_recognizers/logical_recognizers.hpp"

void recognizeEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("==")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::EQUAL, 2, "==", "Equal");
  }
}

void recognizeNotEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("!=")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::NOT_EQUAL, 2, "!=", "Not Equal");
  }
}

void recognizeGreater(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(">") && !lexer.checkKeyword(">=") && !lexer.checkKeyword(">>")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::GREATER, 1, ">", "Greater");
  }
}

void recognizeLess(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("<") && !lexer.checkKeyword("<=") && !lexer.checkKeyword("<<") && !lexer.checkKeyword("<>") &&
      !lexer.checkKeyword("<#>") && !lexer.checkKeyword("<!>")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::LESS, 1, "<", "Less");
  }
}

void recognizeGreaterEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(">=")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::GREATER_EQUAL, 2, ">=", "Greater Equal");
  }
}

void recognizeLessEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("<=")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::LESS_EQUAL, 2, "<=", "Less Equal");
  }
}

void recognizeAnd(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("&&")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::AND, 2, "&&", "And");
  }
}

void recognizeOr(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("||")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::OR, 2, "||", "Or");
  }
}

void recognizeNot(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("!") && !lexer.checkKeyword("!=") && !lexer.checkKeyword("!!")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::NOT, 1, "!", "Not");
  }
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
