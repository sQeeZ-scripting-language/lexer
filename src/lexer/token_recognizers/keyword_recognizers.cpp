#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token recognizeVariableDeclaration(Lexer& lexer) {
    if (lexer.checkKeyword("!!")) {
        lexer.skip(2);
        return {TokenType::TOKEN_VARIABLE_DECLARATION, "!!", "Variable declaration"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeIf(Lexer& lexer) {
    if (lexer.checkKeyword("?") && !lexer.checkKeyword("??") && !lexer.checkKeyword("???")) {
        lexer.skip(1);
        return {TokenType::TOKEN_IF, "?", "Conditional statement"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeElse(Lexer& lexer) {
    if (lexer.checkKeyword("??") && !lexer.checkKeyword("???")) {
        lexer.skip(2);
        return {TokenType::TOKEN_ELSE, "??", "Else statement"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeElseIf(Lexer& lexer) {
    if (lexer.checkKeyword("???")) {
        lexer.skip(3);
        return {TokenType::TOKEN_ELSE_IF, "???", "Else if statement"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeFor(Lexer& lexer) {
    if (lexer.checkKeyword("@")) {
        lexer.skip(1);
        return {TokenType::TOKEN_FOR, "@", "For loop"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeBreak(Lexer& lexer) {
    if (lexer.checkKeyword("<<")) {
        lexer.skip(2);
        return {TokenType::TOKEN_BREAK, "<<", "Break keyword"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeContinue(Lexer& lexer) {
    if (lexer.checkKeyword(">>")) {
        lexer.skip(2);
        return {TokenType::TOKEN_CONTINUE, ">>", "Continue keyword"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeFunction(Lexer& lexer) {
    if (lexer.checkKeyword("$")) {
        lexer.skip(1);
        return {TokenType::TOKEN_FUNCTION, "$", "Function declaration"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

Token recognizeReturn(Lexer& lexer) {
    if (lexer.checkKeyword("=>")) {
        lexer.skip(2);
        return {TokenType::TOKEN_RETURN, "=>", "Return keyword"};
    }
    return {TokenType::TOKEN_UNKNOWN, "Unknown"};
}

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["!!"] = recognizeVariableDeclaration;
    tokenRecognizers["?"] = recognizeIf;
    tokenRecognizers["??"] = recognizeElse;
    tokenRecognizers["???"] = recognizeElseIf;
    tokenRecognizers["@"] = recognizeFor;
    tokenRecognizers["<<"] = recognizeBreak;
    tokenRecognizers[">>"] = recognizeContinue;
    tokenRecognizers["$"] = recognizeFunction;
    tokenRecognizers["=>"] = recognizeReturn;
}
