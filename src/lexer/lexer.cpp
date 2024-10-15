#include "lexer/lexer.hpp"

#include "lexer/token_recognizers/keyword_recognizers.hpp"
#include "lexer/token_recognizers/log_recognizers.hpp"
#include "lexer/token_recognizers/logical_recognizers.hpp"
#include "lexer/token_recognizers/operator_recognizers.hpp"
#include "lexer/token_recognizers/syntax_recognizers.hpp"
#include "lexer/tokens/token.hpp"

std::unordered_map<std::string, bool> lexerState;

Lexer::Lexer(const std::string& code) : code(code), pos(0) {
  lexerState["insideString"] = false;
  lexerState["endOfString"] = false;
  registerTokenRecognizers();
}

void Lexer::registerTokenRecognizers() {
  registerSyntaxRecognizers(tokenRecognizers);
  registerKeywordRecognizers(tokenRecognizers);
  registerOperatorRecognizers(tokenRecognizers);
  registerLogicalRecognizers(tokenRecognizers);
  registerLogRecognizers(tokenRecognizers);
}

void Lexer::log(Token token, bool devMode) {
  if (devMode) {
    std::cout << token.toString(pos) << std::endl;
  }
}

std::vector<Token> Lexer::tokenize(bool devMode) {
  DataRecognizer dataRecognizer;
  Token previousToken = {BasicToken::INIT, 0, "\0", "BasicToken::INIT", "Initialize Lexer"};
  tokens.push_back(previousToken);
  log(previousToken, devMode);

  do {
    skipWhitespace();
    std::unique_ptr<Token> tokenPtr;
    if (isEOF())
      tokenPtr =
          std::make_unique<Token>(BasicToken::TOKEN_EOF, 0, "EOF", "BasicToken::TOKEN_EOF", "The end of the file");
    if (tokenPtr == nullptr) lexSpecialCases(previousToken, dataRecognizer, tokenPtr);
    if (tokenPtr == nullptr) getNextToken(tokenPtr);
    if (tokenPtr == nullptr) dataRecognizer.getNextToken(extractNextToken(), tokenPtr);
    tokens.push_back(std::move(*tokenPtr));
    skip(tokenPtr->size);
    previousToken = tokens.back();
    log(previousToken, devMode);
  } while (!(previousToken.tag == Token::TypeTag::BASIC && previousToken.type.basicToken == BasicToken::TOKEN_EOF));
  return tokens;
}

void Lexer::lexSpecialCases(Token previousToken, DataRecognizer& dataRecognizer, std::unique_ptr<Token>& tokenPtr) {
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::INLINE_COMMENT) {
    dataRecognizer.extractCommentLiteral(pos, code, tokenPtr);
    return;
  }
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::DOUBLE_QUOTE &&
      !lexerState["insideString"]) {
    if (lexerState["endOfString"]) {
      lexerState["endOfString"] = false;
      return;
    }
    lexerState["insideString"] = true;
    dataRecognizer.extractStringLiteral(pos, code, tokenPtr);
    return;
  }
  if (previousToken.tag == Token::TypeTag::DATA && previousToken.type.dataToken == DataToken::STRING_LITERAL &&
      lexerState["insideString"]) {
    lexerState["insideString"] = false;
    lexerState["endOfString"] = true;
    tokenPtr = std::make_unique<Token>(SyntaxToken::DOUBLE_QUOTE, 1, "\"", "SyntaxToken::DOUBLE_QUOTE", "Double Quote");
    return;
  }
}

void Lexer::getNextToken(std::unique_ptr<Token>& tokenPtr) {
  skipWhitespace();
  if (isEOF()) {
    tokenPtr = std::make_unique<Token>(BasicToken::TOKEN_EOF, 0, "EOF", "BasicToken::TOKEN_EOF", "The end of the file");
    return;
  }
  for (const auto& recognizer : tokenRecognizers) {
    recognizer.second(*this, tokenPtr);
    if (tokenPtr) return;
  }
}

std::string Lexer::extractNextToken() {
  skipWhitespace();
  if (isEOF()) return "";
  size_t start = pos;
  size_t position = pos;
  if (std::isalpha(code[start]) || code[start] == '_') {
    while (position < code.size() && (std::isalnum(code[position]) || code[position] == '_')) {
      ++position;
    }
  } else if (std::isdigit(code[start])) {
    while (position < code.size() && std::isdigit(code[position])) {
      ++position;
    }
    if (position < code.size() && code[position] == '.') {
      ++position;
      while (position < code.size() && std::isdigit(code[position])) {
        ++position;
      }
    }
  } else {
    while (position < code.size() && !std::isspace(code[position])) {
      ++position;
    }
  }
  return code.substr(start, position - start);
}

bool Lexer::checkKeyword(const std::string& keyword) { return code.substr(pos, keyword.size()) == keyword; }

void Lexer::skip(size_t size) { pos += size; }

void Lexer::skipWhitespace() {
  while (!isEOF() && std::isspace(peek())) {
    advance();
  }
}

char Lexer::advance() {
  if (!isEOF()) {
    pos++;
  }
  return peek();
}

char Lexer::peek() {
  if (isEOF()) {
    return '\0';
  }
  return code[pos];
}

bool Lexer::isEOF() { return pos >= code.size(); }
