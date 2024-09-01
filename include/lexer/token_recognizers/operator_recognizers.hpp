#ifndef OPERATOR_RECOGNIZERS_HPP
#define OPERATOR_RECOGNIZERS_HPP

#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = Token* (*)(Lexer&);

Token* recognizeAssign(Lexer& lexer);
Token* recognizeAddition(Lexer& lexer);
Token* recognizeSubtraction(Lexer& lexer);
Token* recognizeMultiplication(Lexer& lexer);
Token* recognizeDivision(Lexer& lexer);
Token* recognizeModulus(Lexer& lexer);
Token* recognizeAdditionAssignment(Lexer& lexer);
Token* recognizeSubtractionAssignment(Lexer& lexer);
Token* recognizeMultiplicationAssignment(Lexer& lexer);
Token* recognizeDivisionAssignment(Lexer& lexer);
Token* recognizeModulusAssignment(Lexer& lexer);
Token* recognizeIncrement(Lexer& lexer);
Token* recognizeDecrement(Lexer& lexer);
Token* recognizePotentiation(Lexer& lexer);
Token* recognizeFloorDivision(Lexer& lexer);

bool checkIfOperator(const std::string& keyword, Lexer& lexer);

void registerOperatorRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
