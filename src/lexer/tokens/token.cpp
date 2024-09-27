#include "lexer/tokens/token.hpp"

const char* tags[] = {"BASIC", "DATA", "ERROR", "KEYWORD", "LOG", "LOGICAL", "OPERATOR", "SYNTAX"};

std::string Token::toString() const {
  std::ostringstream oss;
  oss << "###Token###"
      << ",\nTag: " << tags[static_cast<int>(tag)] << ",\nSize: " << size << ",\nValue: \"" << value
      << "\",\nPlainText: \"" << plainText << "\",\nDesc: \"" << desc << "\n";
  return oss.str();
}
