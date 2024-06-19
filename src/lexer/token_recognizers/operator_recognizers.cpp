#include "lexer/token_recognizers/operator_recognizers.hpp"

Token recognizeAssign(Lexer& lexer) {
    if (lexer.checkKeyword("=") && !lexer.checkKeyword("==")) {
        lexer.skip(1);
        return {TokenType::TOKEN_ASSIGN, "=", "Assign"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeAddition(Lexer& lexer) {
    if (lexer.checkKeyword("+") && !lexer.checkKeyword("++") && !lexer.checkKeyword("+=")) {
        lexer.skip(1);
        return {TokenType::TOKEN_ADDITION, "+", "Addition"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeSubtraction(Lexer& lexer) {
    if (lexer.checkKeyword("-") && !lexer.checkKeyword("--") && !lexer.checkKeyword("-=")) {
        lexer.skip(1);
        return {TokenType::TOKEN_SUBTRACTION, "-", "Subtraction"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeMultiplication(Lexer& lexer) {
    if (lexer.checkKeyword("*") && !lexer.checkKeyword("**") && !lexer.checkKeyword("*=")) {
        lexer.skip(1);
        return {TokenType::TOKEN_MULTIPLICATION, "*", "Multiplication"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDivision(Lexer& lexer) {
    if (lexer.checkKeyword("/") && !lexer.checkKeyword("//") && !lexer.checkKeyword("/=")) {
        lexer.skip(1);
        return {TokenType::TOKEN_DIVISION, "/", "Division"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeModulus(Lexer& lexer) {
    if (lexer.checkKeyword("%") && !lexer.checkKeyword("%=")) {
        lexer.skip(1);
        return {TokenType::TOKEN_MODULUS, "%", "Modulus"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeAdditionAssignment(Lexer& lexer) {
    if (lexer.checkKeyword("+=")) {
        lexer.skip(2);
        return {TokenType::TOKEN_ADDITION_ASSIGNMENT, "+=", "Addition Assignment"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeSubtractionAssignment(Lexer& lexer) {
    if (lexer.checkKeyword("-=")) {
        lexer.skip(2);
        return {TokenType::TOKEN_SUBTRACTION_ASSIGNMENT, "-=", "Subtraction Assignment"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeMultiplicationAssignment(Lexer& lexer) {
    if (lexer.checkKeyword("*=")) {
        lexer.skip(2);
        return {TokenType::TOKEN_MULTIPLICATION_ASSIGNMENT, "*=", "Multiplication Assignment"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDivisionAssignment(Lexer& lexer) {
    if (lexer.checkKeyword("/=")) {
        lexer.skip(2);
        return {TokenType::TOKEN_DIVISION_ASSIGNMENT, "/=", "Division Assignment"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeModulusAssignment(Lexer& lexer) {
    if (lexer.checkKeyword("%=")) {
        lexer.skip(2);
        return {TokenType::TOKEN_MODULUS_ASSIGNMENT, "%=", "Modulus Assignment"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeIncrement(Lexer& lexer) {
    if (lexer.checkKeyword("++")) {
        lexer.skip(2);
        return {TokenType::TOKEN_INCREMENT, "++", "Increment"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDecrement(Lexer& lexer) {
    if (lexer.checkKeyword("--")) {
        lexer.skip(2);
        return {TokenType::TOKEN_DECREMENT, "--", "Decrement"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizePotentiation(Lexer& lexer) {
    if (lexer.checkKeyword("**")) {
        lexer.skip(2);
        return {TokenType::TOKEN_POTENTIATION, "**", "Potentiation"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeFloorDivision(Lexer& lexer) {
    if (lexer.checkKeyword("//")) {
        lexer.skip(2);
        return {TokenType::TOKEN_FLOOR_DIVISION, "//", "Floor Division"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
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
