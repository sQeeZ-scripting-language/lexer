#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token recognizeIfKeyword(Lexer& lexer) {
    if (checkIfKeyword("if", lexer)) {
        lexer.currentPosition += 2;
        return {TokenType::TOKEN_IF, "if"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeElseKeyword(Lexer& lexer) {
    if (checkIfKeyword("else", lexer)) {
        lexer.currentPosition += 4;
        return {TokenType::TOKEN_ELSE, "else"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

bool checkIfKeyword(const std::string& keyword, Lexer& lexer) {
    return lexer.code.substr(lexer.currentPosition, keyword.size()) == keyword
        && lexer.currentPosition + keyword.size() < lexer.code.size()
        && !isalpha(lexer.code[lexer.currentPosition + keyword.size()]);
}

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["if"] = recognizeIfKeyword;
    tokenRecognizers["else"] = recognizeElseKeyword;
}
