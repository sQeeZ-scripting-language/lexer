#include "lexer/token_recognizers/operator_recognizers.hpp"

Token* recognizeAssign(Lexer& lexer) {
  return lexer.checkKeyword("=") && !lexer.checkKeyword("==") ? new Token{OperatorToken::ASSIGN, 1, "=", "Assign"}
                                                              : nullptr;
}

Token* recognizeAddition(Lexer& lexer) {
  return lexer.checkKeyword("+") && !lexer.checkKeyword("++") && !lexer.checkKeyword("+=")
             ? new Token{OperatorToken::ADDITION, 1, "+", "Addition"}
             : nullptr;
}

Token* recognizeSubtraction(Lexer& lexer) {
  return lexer.checkKeyword("-") && !lexer.checkKeyword("--") && !lexer.checkKeyword("-=") && !lexer.checkKeyword("->")
             ? new Token{OperatorToken::SUBTRACTION, 1, "-", "Subtraction"}
             : nullptr;
}

Token* recognizeMultiplication(Lexer& lexer) {
  return lexer.checkKeyword("*") && !lexer.checkKeyword("**") && !lexer.checkKeyword("*=")
             ? new Token{OperatorToken::MULTIPLICATION, 1, "*", "Multiplication"}
             : nullptr;
}

Token* recognizeDivision(Lexer& lexer) {
  return lexer.checkKeyword("/") && !lexer.checkKeyword("//") && !lexer.checkKeyword("/=")
             ? new Token{OperatorToken::DIVISION, 1, "/", "Division"}
             : nullptr;
}

Token* recognizeModulus(Lexer& lexer) {
  return lexer.checkKeyword("%") && !lexer.checkKeyword("%=") ? new Token{OperatorToken::MODULUS, 1, "%", "Modulus"}
                                                              : nullptr;
}

Token* recognizeAdditionAssignment(Lexer& lexer) {
  return lexer.checkKeyword("+=") ? new Token{OperatorToken::ADDITION_ASSIGNMENT, 2, "+=", "Addition Assignment"}
                                  : nullptr;
}

Token* recognizeSubtractionAssignment(Lexer& lexer) {
  return lexer.checkKeyword("-=") ? new Token{OperatorToken::SUBTRACTION_ASSIGNMENT, 2, "-=", "Subtraction Assignment"}
                                  : nullptr;
}

Token* recognizeMultiplicationAssignment(Lexer& lexer) {
  return lexer.checkKeyword("*=")
             ? new Token{OperatorToken::MULTIPLICATION_ASSIGNMENT, 2, "*=", "Multiplication Assignment"}
             : nullptr;
}

Token* recognizeDivisionAssignment(Lexer& lexer) {
  return lexer.checkKeyword("/=") ? new Token{OperatorToken::DIVISION_ASSIGNMENT, 2, "/=", "Division Assignment"}
                                  : nullptr;
}

Token* recognizeModulusAssignment(Lexer& lexer) {
  return lexer.checkKeyword("%=") ? new Token{OperatorToken::MODULUS_ASSIGNMENT, 2, "%=", "Modulus Assignment"}
                                  : nullptr;
}

Token* recognizeIncrement(Lexer& lexer) {
  return lexer.checkKeyword("++") ? new Token{OperatorToken::INCREMENT, 2, "++", "Increment"} : nullptr;
}

Token* recognizeDecrement(Lexer& lexer) {
  return lexer.checkKeyword("--") ? new Token{OperatorToken::DECREMENT, 2, "--", "Decrement"} : nullptr;
}

Token* recognizePotentiation(Lexer& lexer) {
  return lexer.checkKeyword("**") ? new Token{OperatorToken::POTENTIATION, 2, "**", "Potentiation"} : nullptr;
}

Token* recognizeFloorDivision(Lexer& lexer) {
  return lexer.checkKeyword("//") ? new Token{OperatorToken::FLOOR_DIVISION, 2, "//", "Floor Division"} : nullptr;
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
