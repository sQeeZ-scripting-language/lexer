#include "lexer/token_recognizers/syntax_recognizers.hpp"

Token recognizeSemicolon(Lexer& lexer) {
    if (lexer.checkKeyword(";")) {
        lexer.skip(1);
        return {TokenType::TOKEN_SEMICOLON, ";", "Semicolon"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeComma(Lexer& lexer) {
    if (lexer.checkKeyword(",")) {
        lexer.skip(1);
        return {TokenType::TOKEN_COMMA, ",", "Comma"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDot(Lexer& lexer) {
    if (lexer.checkKeyword(".")) {
        lexer.skip(1);
        return {TokenType::TOKEN_DOT, ".", "Dot"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeSingleQuote(Lexer& lexer) {
    if (lexer.checkKeyword("'")) {
        lexer.skip(1);
        return {TokenType::TOKEN_SINGLE_QUOTE, "'", "Single Quote"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeDoubleQuote(Lexer& lexer) {
    if (lexer.checkKeyword("\"")) {
        lexer.skip(1);
        return {TokenType::TOKEN_DOUBLE_QUOTE, "\"", "Double Quote"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeOpenParenthesis(Lexer& lexer) {
    if (lexer.checkKeyword("(")) {
        lexer.skip(1);
        return {TokenType::TOKEN_OPEN_PARENTHESIS, "(", "Open Parenthesis"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeCloseParenthesis(Lexer& lexer) {
    if (lexer.checkKeyword(")")) {
        lexer.skip(1);
        return {TokenType::TOKEN_CLOSE_PARENTHESIS, ")", "Close Parenthesis"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeOpenBracket(Lexer& lexer) {
    if (lexer.checkKeyword("[")) {
        lexer.skip(1);
        return {TokenType::TOKEN_OPEN_BRACKET, "[", "Open Bracket"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeCloseBracket(Lexer& lexer) {
    if (lexer.checkKeyword("]")) {
        lexer.skip(1);
        return {TokenType::TOKEN_CLOSE_BRACKET, "]", "Close Bracket"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeOpenBrace(Lexer& lexer) {
    if (lexer.checkKeyword("{")) {
        lexer.skip(1);
        return {TokenType::TOKEN_OPEN_BRACE, "{", "Open Brace"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeCloseBrace(Lexer& lexer) {
    if (lexer.checkKeyword("}")) {
        lexer.skip(1);
        return {TokenType::TOKEN_CLOSE_BRACE, "}", "Close Brace"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeArrow(Lexer& lexer) {
    if (lexer.checkKeyword("->")) {
        lexer.skip(2);
        return {TokenType::TOKEN_ARROW, "->", "Arrow"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

void registerSyntaxRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers[";"] = recognizeSemicolon;
    tokenRecognizers[","] = recognizeComma;
    tokenRecognizers["."] = recognizeDot;
    tokenRecognizers["'"] = recognizeSingleQuote;
    tokenRecognizers["\""] = recognizeDoubleQuote;
    tokenRecognizers["("] = recognizeOpenParenthesis;
    tokenRecognizers[")"] = recognizeCloseParenthesis;
    tokenRecognizers["["] = recognizeOpenBracket;
    tokenRecognizers["]"] = recognizeCloseBracket;
    tokenRecognizers["{"] = recognizeOpenBrace;
    tokenRecognizers["}"] = recognizeCloseBrace;
    tokenRecognizers["->"] = recognizeArrow;
}
