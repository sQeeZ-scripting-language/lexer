#ifndef OPERATOR_RECOGNIZERS_HPP
#define OPERATOR_RECOGNIZERS_HPP

#include <unordered_map>
#include <string>
#include "lexer/lexer.hpp"

using TokenRecognizer = Token (*)(Lexer&);

Token recognizeAdditionOperator(Lexer& lexer);
Token recognizeSubtractionOperator(Lexer& lexer);
Token recognizeMultiplicationOperator(Lexer& lexer);
Token recognizeDivisionOperator(Lexer& lexer);
Token recognizeModulusOperator(Lexer& lexer);
Token recognizeAdditionAssignmentOperator(Lexer& lexer);
Token recognizeSubtractionAssignmentOperator(Lexer& lexer);
Token recognizeMultiplicationAssignmentOperator(Lexer& lexer);
Token recognizeDivisionAssignmentOperator(Lexer& lexer);
Token recognizeModulusAssignmentOperator(Lexer& lexer);
Token recognizeIncrementOperator(Lexer& lexer);
Token recognizeDecrementOperator(Lexer& lexer);
Token recognizePotentiationOperator(Lexer& lexer);
Token recognizeFloorDivisionOperator(Lexer& lexer);

bool checkIfOperator(const std::string& keyword, Lexer& lexer);

void registerOperatorRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif
