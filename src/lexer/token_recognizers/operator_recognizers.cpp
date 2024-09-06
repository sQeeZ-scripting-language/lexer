#include "lexer/token_recognizers/operator_recognizers.hpp"

void recognizeAssign(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("=") && !lexer.checkKeyword("==")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::ASSIGN, 1, "=", "Assign");
  }
}

void recognizeAddition(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("+") && !lexer.checkKeyword("++") && !lexer.checkKeyword("+=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::ADDITION, 1, "+", "Addition");
  }
}

void recognizeSubtraction(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("-") && !lexer.checkKeyword("--") && !lexer.checkKeyword("-=") && !lexer.checkKeyword("->")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::SUBTRACTION, 1, "-", "Subtraction");
  }
}

void recognizeMultiplication(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("*") && !lexer.checkKeyword("**") && !lexer.checkKeyword("*=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::MULTIPLICATION, 1, "*", "Multiplication");
  }
}

void recognizeDivision(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("/") && !lexer.checkKeyword("//") && !lexer.checkKeyword("/=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::DIVISION, 1, "/", "Division");
  }
}

void recognizeModulus(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("%") && !lexer.checkKeyword("%=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::MODULUS, 1, "%", "Modulus");
  }
}

void recognizeAdditionAssignment(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("+=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::ADDITION_ASSIGNMENT, 2, "+=", "Addition Assignment");
  }
}

void recognizeSubtractionAssignment(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("-=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::SUBTRACTION_ASSIGNMENT, 2, "-=", "Subtraction Assignment");
  }
}

void recognizeMultiplicationAssignment(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("*=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::MULTIPLICATION_ASSIGNMENT, 2, "*=", "Multiplication Assignment");
  }
}

void recognizeDivisionAssignment(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("/=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::DIVISION_ASSIGNMENT, 2, "/=", "Division Assignment");
  }
}

void recognizeModulusAssignment(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("%=")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::MODULUS_ASSIGNMENT, 2, "%=", "Modulus Assignment");
  }
}

void recognizeIncrement(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("++")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::INCREMENT, 2, "++", "Increment");
  }
}

void recognizeDecrement(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("--")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::DECREMENT, 2, "--", "Decrement");
  }
}

void recognizePotentiation(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("**")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::POTENTIATION, 2, "**", "Potentiation");
  }
}

void recognizeFloorDivision(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("//")) {
    tokenPtr = std::make_unique<Token>(OperatorToken::FLOOR_DIVISION, 2, "//", "Floor Division");
  }
}

void registerOperatorRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["="] = recognizeAssign;
  tokenRecognizers["+"] = recognizeAddition;
  tokenRecognizers["-"] = recognizeSubtraction;
  tokenRecognizers["*"] = recognizeMultiplication;
  tokenRecognizers["/"] = recognizeDivision;
  tokenRecognizers["%"] = recognizeModulus;
  tokenRecognizers["+="] = recognizeAdditionAssignment;
  tokenRecognizers["-="] = recognizeSubtractionAssignment;
  tokenRecognizers["*="] = recognizeMultiplicationAssignment;
  tokenRecognizers["/="] = recognizeDivisionAssignment;
  tokenRecognizers["%="] = recognizeModulusAssignment;
  tokenRecognizers["++"] = recognizeIncrement;
  tokenRecognizers["--"] = recognizeDecrement;
  tokenRecognizers["**"] = recognizePotentiation;
  tokenRecognizers["//"] = recognizeFloorDivision;
}
