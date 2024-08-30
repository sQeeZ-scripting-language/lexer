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

void lex(const std::string& code) {
  Lexer lexer(code);
  DataRecognizer dataRecognizer;
  std::vector<Token> tokens;
  Token previousToken = {BasicToken::UNKNOWN, 0, "NONE", "Initialize Lexer"};

  do {
    std::cout << "###Token###" << std::endl;
    std::cout << "Value: " << previousToken.value << std::endl;
    std::cout << "Size: " << previousToken.size << std::endl;
    std::cout << "Desc: " << previousToken.desc << std::endl;
    std::cout << "Position: " << lexer.pos << std::endl;
    std::cout << std::endl;
    Token* tokenPtr = lexSpecialCases(previousToken, dataRecognizer, lexer);
    tokens.push_back(tokenPtr != nullptr ? *tokenPtr : lexer.getNextToken());
    previousToken = tokens.back();
  } while (!(previousToken.tag == Token::TypeTag::BASIC && previousToken.type.basicToken == BasicToken::TOKEN_EOF));
}

Token* lexSpecialCases(Token previousToken, DataRecognizer dataRecognizer, Lexer &lexer) {
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::DOUBLE_QUOTE && !lexerState["insideString"]) {
    lexerState["insideString"] = true;
    std::cout << "Recognizing String" << std::endl;
    return dataRecognizer.recognizeString(lexer);
  }
  if (previousToken.tag == Token::TypeTag::SYNTAX && previousToken.type.syntaxToken == SyntaxToken::DOUBLE_QUOTE && lexerState["insideString"]) {
    lexerState["insideString"] = false;
  }
  return nullptr;
}
