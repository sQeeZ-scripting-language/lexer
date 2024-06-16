#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token recognizeIfKeyword(Lexer& lexer) {
    if (lexer.code.substr(lexer.currentPosition, 2) == "if") {
        lexer.currentPosition += 2;
        return {TokenType::TOKEN_IF, "if"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

Token recognizeElseKeyword(Lexer& lexer) {
    if (lexer.code.substr(lexer.currentPosition, 4) == "else") {
        lexer.currentPosition += 4;
        return {TokenType::TOKEN_ELSE, "else"};
    }
    return {TokenType::TOKEN_UNKNOWN, ""};
}

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["if"] = recognizeIfKeyword;
    tokenRecognizers["else"] = recognizeElseKeyword;
}
