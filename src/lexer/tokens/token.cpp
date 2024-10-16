#include "lexer/tokens/token.hpp"

std::string Token::toString() const {
  std::ostringstream oss;
  oss << "###Token###"
      << ",\nTag: " << getTagString() << ",\nType: " << getTypeString() << ",\nSize: " << size << ",\nPos: " << pos << ",\nValue: \""
      << value << "\",\nPlainText: \"" << plainText << "\",\nDesc: \"" << desc << "\n";
  return oss.str();
}

std::string Token::getTagString() const {
  std::size_t pos = plainText.find("::");
  return pos != std::string::npos ? plainText.substr(0, pos) : "";
}

std::string Token::getTypeString() const {
  std::size_t pos = plainText.find("::");
  return pos != std::string::npos ? plainText.substr(pos + 2) : "";
}
