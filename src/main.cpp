#include "main.hpp"

int main(int argc, char* argv[]) {
  bool dev = false;
  bool output = false;
  std::string filename;

  if (argc < 2) {
    std::cerr << "Run \"" << argv[0] << " <filename>.sqz --help\" for more information" << std::endl;
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], "--help") == 0) {
      std::cout << "Usage: " << argv[0] << " <filename>.sqz [--flag]" << std::endl;
      std::cout << "Flags:" << std::endl;
      std::cout << "  --help: Display this information" << std::endl;
      std::cout << "  --dev: Enable developer mode" << std::endl;
      std::cout << "  --output: Export tokens to output.log" << std::endl;
      return 0;
    } else if (std::strcmp(argv[i], "--dev") == 0) {
      dev = true;
    } else if (std::strcmp(argv[i], "--output") == 0) {
      output = true;
    }
  }

  filename = argv[1];
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

  Lexer lexer(code);
  std::vector<Token> tokens = lexer.tokenize(dev);

  if (output) {
    std::ofstream outputFile("output.log");
    if (outputFile.is_open()) {
      for (const auto& token : tokens) {
        outputFile << token.toString() << std::endl;
      }
      outputFile.close();
      std::cout << "Tokens exported to output.log" << std::endl;
    } else {
      std::cerr << "Unable to open file: output.log" << std::endl;
    }
  }

  return 0;
}
