#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token recognizeVariable(Lexer& lexer) {
  if (lexer.checkKeyword("var")) {
    lexer.skip(3);
    return {TokenType::TOKEN_VARIABLE, "var", "Variable declaration"};
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
    return {TokenType::TOKEN_ELSE, "else" "Else statement"};
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
  tokenRecognizers["var"] = recognizeVariable;
  tokenRecognizers["if"] = recognizeIf;
  tokenRecognizers["else"] = recognizeElse;
  tokenRecognizers["elif"] = recognizeElseIf;
  tokenRecognizers["for"] = recognizeFor;
  tokenRecognizers["fn"] = recognizeFunction;
  tokenRecognizers["return"] = recognizeReturn;
}
