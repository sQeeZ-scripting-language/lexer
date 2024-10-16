#include "lexer/token_recognizers/logical_recognizers.hpp"

void recognizeEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("==")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::EQUAL, 2, lexer.pos, "==", "LogicalToken::EQUAL", "Equal");
  }
}

void recognizeNotEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("!=")) {
    tokenPtr =
        std::make_unique<Token>(LogicalToken::NOT_EQUAL, 2, lexer.pos, "!=", "LogicalToken::NOT_EQUAL", "Not Equal");
  }
}

void recognizeGreater(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(">") && !lexer.checkKeyword(">=") && !lexer.checkKeyword(">>")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::GREATER, 1, lexer.pos, ">", "LogicalToken::GREATER", "Greater");
  }
}

void recognizeLess(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("<") && !lexer.checkKeyword("<=") && !lexer.checkKeyword("<<") && !lexer.checkKeyword("<>") &&
      !lexer.checkKeyword("<#>") && !lexer.checkKeyword("<!>")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::LESS, 1, lexer.pos, "<", "LogicalToken::LESS", "Less");
  }
}

void recognizeGreaterEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(">=")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::GREATER_EQUAL, 2, lexer.pos, ">=", "LogicalToken::GREATER_EQUAL",
                                       "Greater Equal");
  }
}

void recognizeLessEqual(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("<=")) {
    tokenPtr =
        std::make_unique<Token>(LogicalToken::LESS_EQUAL, 2, lexer.pos, "<=", "LogicalToken::LESS_EQUAL", "Less Equal");
  }
}

void recognizeAnd(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("&&")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::AND, 2, lexer.pos, "&&", "LogicalToken::AND", "And");
  }
}

void recognizeOr(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("||")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::OR, 2, lexer.pos, "||", "LogicalToken::OR", "Or");
  }
}

void recognizeNot(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("!") && !lexer.checkKeyword("!=") && !lexer.checkKeyword("!!")) {
    tokenPtr = std::make_unique<Token>(LogicalToken::NOT, 1, lexer.pos, "!", "LogicalToken::NOT", "Not");
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
