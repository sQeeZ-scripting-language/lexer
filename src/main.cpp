#include "main.hpp"

int main(int argc, char *argv[]) {
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

  lex(code);
  return 0;
}

std::vector<Token> tokens;

void lex(const std::string& code) {
  Lexer lexer(code);
  Token previousToken = {BasicToken::UNKNOWN, "Unknown", "Initialize Lexer"};

  do {
    std::cout << "###Token###" << std::endl;
    std::cout << "Value: " << previousToken.value << std::endl;
    std::cout << "Desc: " << previousToken.desc << std::endl;
    std::cout << "Position: " << lexer.pos << std::endl;
    std::cout << std::endl;
    tokens.push_back(lexer.getNextToken());
    previousToken = tokens.back();
  } while (previousToken.tag == Token::TypeTag::BASIC && previousToken.type.basicToken == BasicToken::TOKEN_EOF);
}
