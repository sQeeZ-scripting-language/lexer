#include "lexer/token_recognizers/operator_recognizers.hpp"

Token recognizeAssign(Lexer& lexer) {
  if (lexer.checkKeyword("=") && !lexer.checkKeyword("==") && !lexer.checkKeyword("=>")) {
    lexer.skip(1);
    return {OperatorToken::ASSIGN, "=", "Assign"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeAddition(Lexer& lexer) {
  if (lexer.checkKeyword("+") && !lexer.checkKeyword("++") && !lexer.checkKeyword("+=")) {
    lexer.skip(1);
    return {OperatorToken::ADDITION, "+", "Addition"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeSubtraction(Lexer& lexer) {
  if (lexer.checkKeyword("-") && !lexer.checkKeyword("--") && !lexer.checkKeyword("-=") && !lexer.checkKeyword("->")) {
    lexer.skip(1);
    return {OperatorToken::SUBTRACTION, "-", "Subtraction"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeMultiplication(Lexer& lexer) {
  if (lexer.checkKeyword("*") && !lexer.checkKeyword("**") && !lexer.checkKeyword("*=")) {
    lexer.skip(1);
    return {OperatorToken::MULTIPLICATION, "*", "Multiplication"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeDivision(Lexer& lexer) {
  if (lexer.checkKeyword("/") && !lexer.checkKeyword("//") && !lexer.checkKeyword("/=")) {
    lexer.skip(1);
    return {OperatorToken::DIVISION, "/", "Division"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeModulus(Lexer& lexer) {
  if (lexer.checkKeyword("%") && !lexer.checkKeyword("%=")) {
    lexer.skip(1);
    return {OperatorToken::MODULUS, "%", "Modulus"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeAdditionAssignment(Lexer& lexer) {
  if (lexer.checkKeyword("+=")) {
    lexer.skip(2);
    return {OperatorToken::ADDITION_ASSIGNMENT, "+=", "Addition Assignment"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeSubtractionAssignment(Lexer& lexer) {
  if (lexer.checkKeyword("-=")) {
    lexer.skip(2);
    return {OperatorToken::SUBTRACTION_ASSIGNMENT, "-=", "Subtraction Assignment"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeMultiplicationAssignment(Lexer& lexer) {
  if (lexer.checkKeyword("*=")) {
    lexer.skip(2);
    return {OperatorToken::MULTIPLICATION_ASSIGNMENT, "*=", "Multiplication Assignment"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeDivisionAssignment(Lexer& lexer) {
  if (lexer.checkKeyword("/=")) {
    lexer.skip(2);
    return {OperatorToken::DIVISION_ASSIGNMENT, "/=", "Division Assignment"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeModulusAssignment(Lexer& lexer) {
  if (lexer.checkKeyword("%=")) {
    lexer.skip(2);
    return {OperatorToken::MODULUS_ASSIGNMENT, "%=", "Modulus Assignment"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeIncrement(Lexer& lexer) {
  if (lexer.checkKeyword("++")) {
    lexer.skip(2);
    return {OperatorToken::INCREMENT, "++", "Increment"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeDecrement(Lexer& lexer) {
  if (lexer.checkKeyword("--")) {
    lexer.skip(2);
    return {OperatorToken::DECREMENT, "--", "Decrement"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizePotentiation(Lexer& lexer) {
  if (lexer.checkKeyword("**")) {
    lexer.skip(2);
    return {OperatorToken::POTENTIATION, "**", "Potentiation"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeFloorDivision(Lexer& lexer) {
  if (lexer.checkKeyword("//")) {
    lexer.skip(2);
    return {OperatorToken::FLOOR_DIVISION, "//", "Floor Division"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
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
