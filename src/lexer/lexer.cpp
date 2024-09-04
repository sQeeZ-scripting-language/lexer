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
  registerTokenRecognizers();
}

void Lexer::registerTokenRecognizers() {
  registerSyntaxRecognizers(tokenRecognizers);
  registerKeywordRecognizers(tokenRecognizers);
  registerOperatorRecognizers(tokenRecognizers);
  registerLogicalRecognizers(tokenRecognizers);
  registerLogRecognizers(tokenRecognizers);
}

void Lexer::log(Token token) {
  std::cout << "###Token###" << std::endl;
  std::cout << "Value: " << token.value << std::endl;
  std::cout << "Size: " << token.size << std::endl;
  std::cout << "Desc: " << token.desc << std::endl;
  std::cout << std::endl;
}

std::vector<Token> Lexer::lex() {
  DataRecognizer dataRecognizer;
  Token previousToken = {BasicToken::INIT, 0, "\0", "Initialize Lexer"};
  tokens.push_back(previousToken);
  log(previousToken);

  do {
    skipWhitespace();
    Token* tokenPtr = isEOF() ? new Token{BasicToken::TOKEN_EOF, 0, "EOF", "The end of the file"} : nullptr;
    if (tokenPtr == nullptr) tokenPtr = lexSpecialCases(previousToken, dataRecognizer);
    if (tokenPtr == nullptr) tokenPtr = getNextToken();
    if (tokenPtr == nullptr) tokenPtr = dataRecognizer.recognizeNumericValue(extractToken());
    if (tokenPtr == nullptr) tokenPtr = dataRecognizer.recognizeIdentifier(extractToken());
    if (tokenPtr != nullptr) {
      tokens.push_back(*tokenPtr);
      skip(tokenPtr->size);
    } else {
      tokens.push_back({BasicToken::UNKNOWN, 1, std::string(1, peek()), "Unknown Token"});
      advance();
    }
    previousToken = tokens.back();
    log(previousToken);
  } while (!(previousToken.tag == Token::TypeTag::BASIC && previousToken.type.basicToken == BasicToken::TOKEN_EOF));
  return tokens;
}

Token* Lexer::lexSpecialCases(Token previousToken, DataRecognizer& dataRecognizer) {
  if (previousToken.tag == Token::TypeTag::KEYWORD && previousToken.type.keywordToken == KeywordToken::FUNCTION) {
    return dataRecognizer.storeIdentifier(extractToken(), 'F');
  }
  if (previousToken.tag == Token::TypeTag::KEYWORD && previousToken.type.keywordToken == KeywordToken::VARIABLE) {
    return dataRecognizer.storeIdentifier(extractToken(), 'V');
  }
  if (previousToken.tag == Token::TypeTag::KEYWORD && previousToken.type.keywordToken == KeywordToken::CONSTANT) {
    return dataRecognizer.storeIdentifier(extractToken(), 'C');
  }
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::DOUBLE_QUOTE &&
      !lexerState["insideString"]) {
    lexerState["insideString"] = true;
    return extractStringValue();
  }
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::DOUBLE_QUOTE &&
      lexerState["insideString"]) {
    lexerState["insideString"] = false;
    return nullptr;
  }
  return nullptr;
}

Token* Lexer::getNextToken() {
  skipWhitespace();
  if (isEOF()) {
    return new Token{BasicToken::TOKEN_EOF, 0, "EOF", "The end of the file"};
  }

  for (const auto& recognizer : tokenRecognizers) {
    size_t originalPosition = pos;
    Token* tokenPtr = recognizer.second(*this);
    if (tokenPtr != nullptr) return tokenPtr;
  }
  return nullptr;
}

Token *Lexer::extractStringValue() {
  std::vector<char> charList;
  bool isClosed = false;
  while (!isEOF()) {
    char current = peek();
    if (current == '"' && (charList.empty() || charList.back() != '\\')) {
      isClosed = true;
      break;
    }
    charList.push_back(current);
    advance();
  }
  std::string value(charList.begin(), charList.end());
  return new Token{DataToken::STRING_VALUE, static_cast<int>(charList.size()), value, "String Value"};
}

std::string Lexer::extractToken() {
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
    ++position;
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
