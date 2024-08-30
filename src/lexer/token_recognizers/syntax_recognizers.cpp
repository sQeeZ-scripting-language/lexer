#include "lexer/token_recognizers/syntax_recognizers.hpp"

Token* recognizeSemicolon(Lexer& lexer) {
  return lexer.checkKeyword(";") ? new Token{SyntaxToken::SEMICOLON, 1, ";", "Semicolon"} : nullptr;
}

Token* recognizeComma(Lexer& lexer) {
  return lexer.checkKeyword(",") ? new Token{SyntaxToken::COMMA, 1, ",", "Comma"} : nullptr;
}

Token* recognizeDot(Lexer& lexer) {
  return lexer.checkKeyword(".") ? new Token{SyntaxToken::DOT, 1, ".", "Dot"} : nullptr;
}

Token* recognizeColon(Lexer& lexer) {
  return lexer.checkKeyword(":") ? new Token{SyntaxToken::COLON, 1, ":", "Colon"} : nullptr;
}

Token* recognizeSingleQuote(Lexer& lexer) {
  return lexer.checkKeyword("'") ? new Token{SyntaxToken::SINGLE_QUOTE, 1, "'", "Single Quote"} : nullptr;
}

Token* recognizeDoubleQuote(Lexer& lexer) {
  return lexer.checkKeyword("\"") ? new Token{SyntaxToken::DOUBLE_QUOTE, 1, "\"", "Double Quote"} : nullptr;
}

Token* recognizeOpenParenthesis(Lexer& lexer) {
  return lexer.checkKeyword("(") ? new Token{SyntaxToken::OPEN_PARENTHESIS, 1, "(", "Open Parenthesis"} : nullptr;
}

Token* recognizeCloseParenthesis(Lexer& lexer) {
  return lexer.checkKeyword(")") ? new Token{SyntaxToken::CLOSE_PARENTHESIS, 1, ")", "Close Parenthesis"} : nullptr;
}

Token* recognizeOpenBracket(Lexer& lexer) {
  return lexer.checkKeyword("[") ? new Token{SyntaxToken::OPEN_BRACKET, 1, "[", "Open Bracket"} : nullptr;
}

Token* recognizeCloseBracket(Lexer& lexer) {
  return lexer.checkKeyword("]") ? new Token{SyntaxToken::CLOSE_BRACKET, 1, "]", "Close Bracket"} : nullptr;
}

Token* recognizeOpenBrace(Lexer& lexer) {
  return lexer.checkKeyword("{") ? new Token{SyntaxToken::OPEN_BRACE, 1, "{", "Open Brace"} : nullptr;
}

Token* recognizeCloseBrace(Lexer& lexer) {
  return lexer.checkKeyword("}") ? new Token{SyntaxToken::CLOSE_BRACE, 1, "}", "Close Brace"} : nullptr;
}

Token* recognizeArrow(Lexer& lexer) {
  return lexer.checkKeyword("->") ? new Token{SyntaxToken::ARROW, 2, "->", "Arrow"} : nullptr;
}

Token* recognizeHashtag(Lexer& lexer) {
  return lexer.checkKeyword("#") ? new Token{SyntaxToken::HASHTAG, 1, "#", "Hashtag"} : nullptr;
}

void registerSyntaxRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers[";"] = recognizeSemicolon;
  tokenRecognizers[","] = recognizeComma;
  tokenRecognizers["."] = recognizeDot;
  tokenRecognizers[":"] = recognizeColon;
  tokenRecognizers["'"] = recognizeSingleQuote;
  tokenRecognizers["\""] = recognizeDoubleQuote;
  tokenRecognizers["("] = recognizeOpenParenthesis;
  tokenRecognizers[")"] = recognizeCloseParenthesis;
  tokenRecognizers["["] = recognizeOpenBracket;
  tokenRecognizers["]"] = recognizeCloseBracket;
  tokenRecognizers["{"] = recognizeOpenBrace;
  tokenRecognizers["}"] = recognizeCloseBrace;
  tokenRecognizers["->"] = recognizeArrow;
  tokenRecognizers["#"] = recognizeHashtag;
}
