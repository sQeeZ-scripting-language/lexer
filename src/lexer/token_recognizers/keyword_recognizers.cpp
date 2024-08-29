#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token recognizeVariable(Lexer& lexer) {
  if (lexer.checkKeyword("var")) {
    lexer.skip(3);
    return {KeywordToken::VARIABLE, "var", "Variable declaration"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeIf(Lexer& lexer) {
  if (lexer.checkKeyword("if")) {
    lexer.skip(2);
    return {KeywordToken::IF, "if", "Conditional statement"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeElse(Lexer& lexer) {
  if (lexer.checkKeyword("else")) {
    lexer.skip(4);
    return {KeywordToken::ELSE, "else", "Else statement"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeElseIf(Lexer& lexer) {
  if (lexer.checkKeyword("elif")) {
    lexer.skip(4);
    return {KeywordToken::ELSE_IF, "elif", "Else if statement"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeFor(Lexer& lexer) {
  if (lexer.checkKeyword("for")) {
    lexer.skip(3);
    return {KeywordToken::FOR, "for", "For loop"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeFunction(Lexer& lexer) {
  if (lexer.checkKeyword("fn")) {
    lexer.skip(2);
    return {KeywordToken::FUNCTION, "fn", "Function declaration"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeReturn(Lexer& lexer) {
  if (lexer.checkKeyword("return")) {
    lexer.skip(6);
    return {KeywordToken::RETURN, "return", "Return keyword"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
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
