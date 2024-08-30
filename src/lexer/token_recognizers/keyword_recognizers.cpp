#include "lexer/token_recognizers/keyword_recognizers.hpp"

Token* recognizeVariable(Lexer& lexer) {
  return lexer.checkKeyword("var") ? new Token{KeywordToken::VARIABLE, 3, "var", "Variable declaration"} : nullptr;
}

Token* recognizeConstant(Lexer& lexer) {
  return lexer.checkKeyword("const") ? new Token{KeywordToken::CONSTANT, 5, "const", "Constant declaration"} : nullptr;
}

Token* recognizeIf(Lexer& lexer) {
  return lexer.checkKeyword("if") ? new Token{KeywordToken::IF, 2, "if", "Conditional statement"} : nullptr;
}

Token* recognizeElse(Lexer& lexer) {
  return lexer.checkKeyword("else") ? new Token{KeywordToken::ELSE, 4, "else", "Else statement"} : nullptr;
}

Token* recognizeElseIf(Lexer& lexer) {
  return lexer.checkKeyword("elif") ? new Token{KeywordToken::ELSE_IF, 4, "elif", "Else if statement"} : nullptr;
}

Token* recognizeFor(Lexer& lexer) {
  return lexer.checkKeyword("for") ? new Token{KeywordToken::FOR, 3, "for", "For loop"} : nullptr;
}

Token* recognizeFunction(Lexer& lexer) {
  return lexer.checkKeyword("fn") ? new Token{KeywordToken::FUNCTION, 2, "fn", "Function declaration"} : nullptr;
}

Token* recognizeReturn(Lexer& lexer) {
  return lexer.checkKeyword("return") ? new Token{KeywordToken::RETURN, 6, "return", "Return keyword"} : nullptr;
}

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["var"] = recognizeVariable;
  tokenRecognizers["const"] = recognizeConstant;
  tokenRecognizers["if"] = recognizeIf;
  tokenRecognizers["else"] = recognizeElse;
  tokenRecognizers["elif"] = recognizeElseIf;
  tokenRecognizers["for"] = recognizeFor;
  tokenRecognizers["fn"] = recognizeFunction;
  tokenRecognizers["return"] = recognizeReturn;
}
