#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token recognizeLet(Lexer& lexer) {
    if (lexer.checkKeyword("let")) {
        lexer.skip(3);
        return {TokenType::TOKEN_LET, "let", "Variable declaration"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeConst(Lexer& lexer) {
    if (lexer.checkKeyword("const")) {
        lexer.skip(5);
        return {TokenType::TOKEN_CONST, "const", "Constant declaration"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeIf(Lexer& lexer) {
    if (lexer.checkKeyword("if")) {
        lexer.skip(2);
        return {TokenType::TOKEN_IF, "if", "Conditional statement"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeElse(Lexer& lexer) {
    if (lexer.checkKeyword("else")) {
        lexer.skip(4);
        return {TokenType::TOKEN_ELSE, "else", "Else statement"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeElseIf(Lexer& lexer) {
    if (lexer.checkKeyword("elif")) {
        lexer.skip(4);
        return {TokenType::TOKEN_ELSE_IF, "elif", "Else if statement"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeFor(Lexer& lexer) {
    if (lexer.checkKeyword("for")) {
        lexer.skip(3);
        return {TokenType::TOKEN_FOR, "for", "For loop"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeIn(Lexer& lexer) {
    if (lexer.checkKeyword("in")) {
        lexer.skip(2);
        return {TokenType::TOKEN_IN, "in", "In keyword"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeBreak(Lexer& lexer) {
    if (lexer.checkKeyword("break")) {
        lexer.skip(5);
        return {TokenType::TOKEN_BREAK, "break", "Break keyword"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeContinue(Lexer& lexer) {
    if (lexer.checkKeyword("continue")) {
        lexer.skip(8);
        return {TokenType::TOKEN_CONTINUE, "continue", "Continue keyword"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeFunction(Lexer& lexer) {
    if (lexer.checkKeyword("fn")) {
        lexer.skip(2);
        return {TokenType::TOKEN_FUNCTION, "fn", "Function declaration"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeReturn(Lexer& lexer) {
    if (lexer.checkKeyword("return")) {
        lexer.skip(6);
        return {TokenType::TOKEN_RETURN, "return", "Return keyword"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["let"] = recognizeLet;
    tokenRecognizers["const"] = recognizeConst;
    tokenRecognizers["if"] = recognizeIf;
    tokenRecognizers["else"] = recognizeElse;
    tokenRecognizers["elif"] = recognizeElseIf;
    tokenRecognizers["for"] = recognizeFor;
    tokenRecognizers["in"] = recognizeIn;
    tokenRecognizers["break"] = recognizeBreak;
    tokenRecognizers["continue"] = recognizeContinue;
    tokenRecognizers["fn"] = recognizeFunction;
    tokenRecognizers["return"] = recognizeReturn;
}
