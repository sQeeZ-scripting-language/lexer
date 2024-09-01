#include "main.hpp"

std::unordered_map<std::string, bool> lexerState;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename>.sqz" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  std::size_t index = filename.find_last_of(".");
  if (index == std::string::npos || filename.substr(index + 1) != "sqz") {
    std::cerr << "Error: File must have a .sqz extension" << std::endl;
    return 1;
  }

  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Cannot read file: " << filename << std::endl;
    return 1;
  }

  std::string code;
  std::string line;
  while (std::getline(file, line)) {
    code += line + "\n";
  }

  lexerState["insideString"] = false;

  lex(code);

  return 0;
}

std::vector<Token> lex(const std::string& code) {
  Lexer lexer(code);
  DataRecognizer dataRecognizer;
  Token previousToken = {BasicToken::INIT, 0, "\0", "Initialize Lexer"};
  tokens.push_back(previousToken);
  logToken(previousToken);

  do {
    lexer.skipWhitespace();
    Token* tokenPtr = lexer.isEOF() ? new Token{BasicToken::TOKEN_EOF, 0, "EOF", "The end of the file"} : nullptr;
    if (tokenPtr == nullptr) tokenPtr = lexSpecialCases(previousToken, dataRecognizer, lexer);
    if (tokenPtr == nullptr) tokenPtr = lexer.getNextToken();
    if (tokenPtr == nullptr) tokenPtr = dataRecognizer.recognizeNumericValue(lexer);
    if (tokenPtr == nullptr) tokenPtr = dataRecognizer.recognizeIdentifier(lexer);
    if (tokenPtr != nullptr) {
      tokens.push_back(*tokenPtr);
      lexer.skip(tokenPtr->size);
    } else {
      tokens.push_back({BasicToken::UNKNOWN, 1, std::string(1, lexer.peek()), "Unknown Token"});
      lexer.advance();
    }
    previousToken = tokens.back();
    logToken(previousToken);
  } while (!(previousToken.tag == Token::TypeTag::BASIC && previousToken.type.basicToken == BasicToken::TOKEN_EOF));
  return tokens;
}

Token* lexSpecialCases(Token previousToken, DataRecognizer& dataRecognizer, Lexer& lexer) {
  if (previousToken.tag == Token::TypeTag::KEYWORD && previousToken.type.keywordToken == KeywordToken::FUNCTION) {
    return dataRecognizer.storeIdentifier(lexer, 'F');
  }
  if (previousToken.tag == Token::TypeTag::KEYWORD && previousToken.type.keywordToken == KeywordToken::VARIABLE) {
    return dataRecognizer.storeIdentifier(lexer, 'V');
  }
  if (previousToken.tag == Token::TypeTag::KEYWORD && previousToken.type.keywordToken == KeywordToken::CONSTANT) {
    return dataRecognizer.storeIdentifier(lexer, 'C');
  }
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::DOUBLE_QUOTE &&
      !lexerState["insideString"]) {
    lexerState["insideString"] = true;
    return dataRecognizer.recognizeString(lexer);
  }
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::DOUBLE_QUOTE &&
      lexerState["insideString"]) {
    lexerState["insideString"] = false;
    return nullptr;
  }
  return nullptr;
}

void logToken(Token token) {
  std::cout << "###Token###" << std::endl;
  std::cout << "Value: " << token.value << std::endl;
  std::cout << "Size: " << token.size << std::endl;
  std::cout << "Desc: " << token.desc << std::endl;
  std::cout << std::endl;
}