#include "lexer/token_recognizers/syntax_recognizers.hpp"

void recognizeSemicolon(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(";")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::SEMICOLON, 1, ";", "Semicolon");
  }
}

void recognizeComma(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(",")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::COMMA, 1, ",", "Comma");
  }
}

void recognizeDot(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(".")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::DOT, 1, ".", "Dot");
  }
}

void recognizeColon(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(":")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::COLON, 1, ":", "Colon");
  }
}

void recognizeSingleQuote(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("'")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::SINGLE_QUOTE, 1, "'", "Single Quote");
  }
}

void recognizeDoubleQuote(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("\"")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::DOUBLE_QUOTE, 1, "\"", "Double Quote");
  }
}

void recognizeOpenParenthesis(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("(")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::OPEN_PARENTHESIS, 1, "(", "Open Parenthesis");
  }
}

void recognizeCloseParenthesis(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(")")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::CLOSE_PARENTHESIS, 1, ")", "Close Parenthesis");
  }
}

void recognizeOpenBracket(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("[")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::OPEN_BRACKET, 1, "[", "Open Bracket");
  }
}

void recognizeCloseBracket(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("]")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::CLOSE_BRACKET, 1, "]", "Close Bracket");
  }
}

void recognizeOpenBrace(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("{")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::OPEN_BRACE, 1, "{", "Open Brace");
  }
}

void recognizeCloseBrace(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("}")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::CLOSE_BRACE, 1, "}", "Close Brace");
  }
}

void recognizeArrow(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("->")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::ARROW, 2, "->", "Arrow");
  }
}

void recognizeHashtag(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("#")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::HASHTAG, 1, "#", "Hashtag");
  }
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
