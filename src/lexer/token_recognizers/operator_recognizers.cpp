#include "lexer/token_recognizers/operator_recognizers.hpp"

Token recognizeAdditionOperator(Lexer& lexer) {
    if (checkIfOperator("+", lexer)) return {TokenType::TOKEN_ADDITION, "+"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeSubtractionOperator(Lexer& lexer) {
    if (checkIfOperator("-", lexer)) return {TokenType::TOKEN_SUBTRACTION, "-"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeMultiplicationOperator(Lexer& lexer) {
    if (checkIfOperator("*", lexer)) return {TokenType::TOKEN_MULTIPLICATION, "*"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDivisionOperator(Lexer& lexer) {
    if (checkIfOperator("/", lexer)) return {TokenType::TOKEN_DIVISION, "/"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeModulusOperator(Lexer& lexer) {
    if (checkIfOperator("%", lexer)) return {TokenType::TOKEN_MODULUS, "%"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeAdditionAssignmentOperator(Lexer& lexer) {
    if (checkIfOperator("+=", lexer)) return {TokenType::TOKEN_ADDITION_ASSIGNMENT, "+="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeSubtractionAssignmentOperator(Lexer& lexer) {
    if (checkIfOperator("-=", lexer)) return {TokenType::TOKEN_SUBTRACTION_ASSIGNMENT, "-="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeMultiplicationAssignmentOperator(Lexer& lexer) {
    if (checkIfOperator("*=", lexer)) return {TokenType::TOKEN_MULTIPLICATION_ASSIGNMENT, "*="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDivisionAssignmentOperator(Lexer& lexer) {
    if (checkIfOperator("/=", lexer)) return {TokenType::TOKEN_DIVISION_ASSIGNMENT, "/="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeModulusAssignmentOperator(Lexer& lexer) {
    if (checkIfOperator("%=", lexer)) return {TokenType::TOKEN_MODULUS_ASSIGNMENT, "%="};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeIncrementOperator(Lexer& lexer) {
    if (checkIfOperator("++", lexer)) return {TokenType::TOKEN_INCREMENT, "++"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDecrementOperator(Lexer& lexer) {
    if (checkIfOperator("--", lexer)) return {TokenType::TOKEN_DECREMENT, "--"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizePotentiationOperator(Lexer& lexer) {
    if (checkIfOperator("**", lexer)) return {TokenType::TOKEN_POTENTIATION, "**"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeFloorDivisionOperator(Lexer& lexer) {
    if (checkIfOperator("//", lexer)) return {TokenType::TOKEN_FLOOR_DIVISION, "//"};
    return {TokenType::TOKEN_UNKNOWN, ""};
}

bool checkIfOperator(const std::string& keyword, Lexer& lexer) {
    bool isOperator = lexer.code.substr(lexer.currentPosition, keyword.size()) == keyword
        && lexer.currentPosition + keyword.size() < lexer.code.size()
        && !isalpha(lexer.code[lexer.currentPosition + keyword.size()]);
    if (isOperator) lexer.currentPosition += keyword.size();
    return isOperator;
}

void registerOperatorRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["+"] = recognizeAdditionOperator;
    tokenRecognizers["-"] = recognizeSubtractionOperator;
    tokenRecognizers["*"] = recognizeMultiplicationOperator;
    tokenRecognizers["/"] = recognizeDivisionOperator;
    tokenRecognizers["%"] = recognizeModulusOperator;
    tokenRecognizers["+="] = recognizeAdditionAssignmentOperator;
    tokenRecognizers["-="] = recognizeSubtractionAssignmentOperator;
    tokenRecognizers["*="] = recognizeMultiplicationAssignmentOperator;
    tokenRecognizers["/="] = recognizeDivisionAssignmentOperator;
    tokenRecognizers["%="] = recognizeModulusAssignmentOperator;
    tokenRecognizers["++"] = recognizeIncrementOperator;
    tokenRecognizers["--"] = recognizeDecrementOperator;
    tokenRecognizers["**"] = recognizePotentiationOperator;
    tokenRecognizers["//"] = recognizeFloorDivisionOperator;
}
