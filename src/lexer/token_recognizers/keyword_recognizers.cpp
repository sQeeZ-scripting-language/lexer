#include "lexer/token_recognizers/keyword_recognizers.hpp"

void recognizeVariable(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("var")) {
    tokenPtr =
        std::make_unique<Token>(KeywordToken::VARIABLE, 3, "var", "KeywordToken::VARIABLE", "Variable declaration");
  }
}

void recognizeConstant(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("const")) {
    tokenPtr =
        std::make_unique<Token>(KeywordToken::CONSTANT, 5, "const", "KeywordToken::CONSTANT", "Constant declaration");
  }
}

void recognizeIf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("if")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::IF, 2, "if", "KeywordToken::IF", "Conditional statement");
  }
}

void recognizeElse(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("else")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::ELSE, 4, "else", "KeywordToken::ELSE", "Else statement");
  }
}

void recognizeElseIf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("elif")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::ELSE_IF, 4, "elif", "KeywordToken::ELSE_IF", "Else if statement");
  }
}

void recognizeFor(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("for")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::FOR, 3, "for", "KeywordToken::FOR", "For loop");
  }
}

void recognizeFunction(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("fn")) {
    tokenPtr =
        std::make_unique<Token>(KeywordToken::FUNCTION, 2, "fn", "KeywordToken::FUNCTION", "Function declaration");
  }
}

void recognizeReturn(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
  if (lexer.checkKeyword("return")) {
    tokenPtr = std::make_unique<Token>(KeywordToken::RETURN, 6, "return", "KeywordToken::RETURN", "Return keyword");
  }
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
