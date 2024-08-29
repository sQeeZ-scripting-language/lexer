#include "lexer/token_recognizers/syntax_recognizers.hpp"

Token recognizeSemicolon(Lexer& lexer) {
  if (lexer.checkKeyword(";")) {
    lexer.skip(1);
    return {SyntaxToken::SEMICOLON, ";", "Semicolon"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeComma(Lexer& lexer) {
  if (lexer.checkKeyword(",")) {
    lexer.skip(1);
    return {SyntaxToken::COMMA, ",", "Comma"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeDot(Lexer& lexer) {
  if (lexer.checkKeyword(".")) {
    lexer.skip(1);
    return {SyntaxToken::DOT, ".", "Dot"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeColon(Lexer& lexer) {
  if (lexer.checkKeyword(":")) {
    lexer.skip(1);
    return {SyntaxToken::COLON, ":", "Colon"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeSingleQuote(Lexer& lexer) {
  if (lexer.checkKeyword("'")) {
    lexer.skip(1);
    return {SyntaxToken::SINGLE_QUOTE, "'", "Single Quote"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeDoubleQuote(Lexer& lexer) {
  if (lexer.checkKeyword("\"")) {
    lexer.skip(1);
    return {SyntaxToken::DOUBLE_QUOTE, "\"", "Double Quote"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeOpenParenthesis(Lexer& lexer) {
  if (lexer.checkKeyword("(")) {
    lexer.skip(1);
    return {SyntaxToken::OPEN_PARENTHESIS, "(", "Open Parenthesis"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeCloseParenthesis(Lexer& lexer) {
  if (lexer.checkKeyword(")")) {
    lexer.skip(1);
    return {SyntaxToken::CLOSE_PARENTHESIS, ")", "Close Parenthesis"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeOpenBracket(Lexer& lexer) {
  if (lexer.checkKeyword("[")) {
    lexer.skip(1);
    return {SyntaxToken::OPEN_BRACKET, "[", "Open Bracket"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeCloseBracket(Lexer& lexer) {
  if (lexer.checkKeyword("]")) {
    lexer.skip(1);
    return {SyntaxToken::CLOSE_BRACKET, "]", "Close Bracket"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeOpenBrace(Lexer& lexer) {
  if (lexer.checkKeyword("{")) {
    lexer.skip(1);
    return {SyntaxToken::OPEN_BRACE, "{", "Open Brace"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeCloseBrace(Lexer& lexer) {
  if (lexer.checkKeyword("}")) {
    lexer.skip(1);
    return {SyntaxToken::CLOSE_BRACE, "}", "Close Brace"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeArrow(Lexer& lexer) {
  if (lexer.checkKeyword("->")) {
    lexer.skip(2);
    return {SyntaxToken::ARROW, "->", "Arrow"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

Token recognizeHashtag(Lexer& lexer) {
  if (lexer.checkKeyword("#")) {
    lexer.skip(1);
    return {SyntaxToken::HASHTAG, "#", "Hashtag"};
  }
  return {BasicToken::UNKNOWN, "Unknown"};
}

void registerSyntaxRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers[";"] = recognizeSemicolon;
  tokenRecognizers[","] = recognizeComma;
  tokenRecognizers["."] = recognizeDot;
  tokenRecognizers["'"] = recognizeSingleQuote;
  tokenRecognizers[":"] = recognizeColon;
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
