#include "lexer/token_recognizers/keyword_recognizers.hpp"

void recognizeVariable(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("var")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::VARIABLE, 3, lexer.pos, "var", "KeywordToken::VARIABLE",
                                       "Variable declaration");
  }
}

void recognizeConstant(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("const")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::CONSTANT, 5, lexer.pos, "const", "KeywordToken::CONSTANT",
                                       "Constant declaration");
  }
}

void recognizeIf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("if")) {
    tokenPtr =
        std::make_unique<Token>(KeywordToken::IF, 2, lexer.pos, "if", "KeywordToken::IF", "Conditional statement");
  }
}

void recognizeElse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("else")) {
    tokenPtr =
        std::make_unique<Token>(KeywordToken::ELSE, 4, lexer.pos, "else", "KeywordToken::ELSE", "Else statement");
  }
}

void recognizeElseIf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("elif")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::ELSE_IF, 4, lexer.pos, "elif", "KeywordToken::ELSE_IF",
                                       "Else if statement");
  }
}

void recognizeFor(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("for")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::FOR, 3, lexer.pos, "for", "KeywordToken::FOR", "For loop");
  }
}

void recognizeWhile(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("while")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::WHILE, 5, lexer.pos, "while", "KeywordToken::WHILE", "While loop");
  }
}

void recognizeDo(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("do")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::DO, 2, lexer.pos, "do", "KeywordToken::DO", "Do While loop");
  }
}

void recognizeFunction(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("fn")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::FUNCTION, 2, lexer.pos, "fn", "KeywordToken::FUNCTION",
                                       "Function declaration");
  }
}

void recognizeReturn(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("return")) {
    tokenPtr =
        std::make_unique<Token>(KeywordToken::RETURN, 6, lexer.pos, "return", "KeywordToken::RETURN", "Return keyword");
  }
}

void recognizeIn(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("in")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::IN, 2, lexer.pos, "in", "KeywordToken::IN", "In keyword");
  }
}

void recognizeOf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("of")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::OF, 2, lexer.pos, "of", "KeywordToken::OF", "Of keyword");
  }
}

void registerKeywordRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
  tokenRecognizers["var"] = recognizeVariable;
  tokenRecognizers["const"] = recognizeConstant;
  tokenRecognizers["if"] = recognizeIf;
  tokenRecognizers["else"] = recognizeElse;
  tokenRecognizers["elif"] = recognizeElseIf;
  tokenRecognizers["for"] = recognizeFor;
  tokenRecognizers["while"] = recognizeWhile;
  tokenRecognizers["do"] = recognizeDo;
  tokenRecognizers["fn"] = recognizeFunction;
  tokenRecognizers["return"] = recognizeReturn;
  tokenRecognizers["in"] = recognizeIn;
  tokenRecognizers["of"] = recognizeOf;
}
