#include "lexer/token_recognizers/syntax_recognizers.hpp"

void recognizeSemicolon(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(";")) {
    tokenPtr =
        std::make_unique<Token>(SyntaxToken::SEMICOLON, 1, lexer.pos, ";", "SyntaxToken::SEMICOLON", "Semicolon");
  }
}

void recognizeComma(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(",")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::COMMA, 1, lexer.pos, ",", "SyntaxToken::COMMA", "Comma");
  }
}

void recognizeDot(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(".")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::DOT, 1, lexer.pos, ".", "SyntaxToken::DOT", "Dot");
  }
}

void recognizeColon(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(":")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::COLON, 1, lexer.pos, ":", "SyntaxToken::COLON", "Colon");
  }
}

void recognizeSingleQuote(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("'")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::SINGLE_QUOTE, 1, lexer.pos, "'", "SyntaxToken::SINGLE_QUOTE",
                                       "Single Quote");
  }
}

void recognizeDoubleQuote(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("\"")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::DOUBLE_QUOTE, 1, lexer.pos, "\"", "SyntaxToken::DOUBLE_QUOTE",
                                       "Double Quote");
  }
}

void recognizeOpenParenthesis(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("(")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::OPEN_PARENTHESIS, 1, lexer.pos, "(",
                                       "SyntaxToken::OPEN_PARENTHESIS", "Open Parenthesis");
  }
}

void recognizeCloseParenthesis(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword(")")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::CLOSE_PARENTHESIS, 1, lexer.pos, ")",
                                       "SyntaxToken::CLOSE_PARENTHESIS", "Close Parenthesis");
  }
}

void recognizeOpenBracket(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("[")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::OPEN_BRACKET, 1, lexer.pos, "[", "SyntaxToken::OPEN_BRACKET",
                                       "Open Bracket");
  }
}

void recognizeCloseBracket(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("]")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::CLOSE_BRACKET, 1, lexer.pos, "]", "SyntaxToken::CLOSE_BRACKET",
                                       "Close Bracket");
  }
}

void recognizeOpenBrace(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("{")) {
    tokenPtr =
        std::make_unique<Token>(SyntaxToken::OPEN_BRACE, 1, lexer.pos, "{", "SyntaxToken::OPEN_BRACE", "Open Brace");
  }
}

void recognizeCloseBrace(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("}")) {
    tokenPtr =
        std::make_unique<Token>(SyntaxToken::CLOSE_BRACE, 1, lexer.pos, "}", "SyntaxToken::CLOSE_BRACE", "Close Brace");
  }
}

void recognizeInlineComment(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("//")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::INLINE_COMMENT, 2, lexer.pos, "//", "SyntaxToken::INLINE_COMMENT",
                                       "Inline Comment");
  }
}

void recognizePipe(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("|") && !lexer.checkKeyword("|>") && !lexer.checkKeyword("||")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::PIPE, 1, lexer.pos, "|", "SyntaxToken::PIPE", "Pipe");
  }
}

void recognizePipeOperator(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("|>")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::PIPE_OPERATOR, 2, lexer.pos, "|>", "SyntaxToken::PIPE_OPERATOR",
                                       "Pipe Operator");
  }
}

void recognizeQuestionMark(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("?")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::QUESTION_MARK, 1, lexer.pos, "?", "SyntaxToken::QUESTION_MARK",
                                       "Question Mark");
  }
}

void recognizeArrow(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("->")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::ARROW, 2, lexer.pos, "->", "SyntaxToken::ARROW", "Arrow");
  }
}

void recognizeHashtag(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("#")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::HASHTAG, 1, lexer.pos, "#", "SyntaxToken::HASHTAG", "Hashtag");
  }
}

void recognizeAt(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("@")) {
    tokenPtr = std::make_unique<Token>(SyntaxToken::AT, 1, lexer.pos, "@", "SyntaxToken::AT", "AT");
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
  tokenRecognizers["//"] = recognizeInlineComment;
  tokenRecognizers["|"] = recognizePipe;
  tokenRecognizers["|>"] = recognizePipeOperator;
  tokenRecognizers["?"] = recognizeQuestionMark;
  tokenRecognizers["->"] = recognizeArrow;
  tokenRecognizers["#"] = recognizeHashtag;
  tokenRecognizers["@"] = recognizeAt;
}
