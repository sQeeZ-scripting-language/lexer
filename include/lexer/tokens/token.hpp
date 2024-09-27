#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <sstream>
#include <string>

#include "data_tokens.hpp"
#include "error_tokens.hpp"
#include "keyword_tokens.hpp"
#include "log_tokens.hpp"
#include "logical_tokens.hpp"
#include "operator_tokens.hpp"
#include "syntax_tokens.hpp"

enum class BasicToken { INIT, TOKEN_EOF, UNKNOWN };

struct Token {
  enum class TypeTag { BASIC, DATA, ERROR, KEYWORD, LOG, LOGICAL, OPERATOR, SYNTAX } tag;

  union TokenType {
    BasicToken basicToken;
    DataToken dataToken;
    ErrorToken errorToken;
    KeywordToken keywordToken;
    LogToken logToken;
    LogicalToken logicalToken;
    OperatorToken operatorToken;
    SyntaxToken syntaxToken;

    TokenType() {}
    TokenType(BasicToken t) : basicToken(t) {}
    TokenType(DataToken t) : dataToken(t) {}
    TokenType(ErrorToken t) : errorToken(t) {}
    TokenType(KeywordToken t) : keywordToken(t) {}
    TokenType(LogToken t) : logToken(t) {}
    TokenType(LogicalToken t) : logicalToken(t) {}
    TokenType(OperatorToken t) : operatorToken(t) {}
    TokenType(SyntaxToken t) : syntaxToken(t) {}
  } type;

  int size;
  std::string value;
  std::string plainText;
  std::string desc;

  Token(BasicToken b, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::BASIC),
        type(b),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(DataToken d, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::DATA),
        type(d),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(ErrorToken e, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::ERROR),
        type(e),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(KeywordToken k, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::KEYWORD),
        type(k),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(LogToken l, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::LOG),
        type(l),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(LogicalToken l, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::LOGICAL),
        type(l),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(OperatorToken o, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::OPERATOR),
        type(o),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(SyntaxToken s, int size = 0, std::string value = "", std::string plainText = "", std::string desc = "")
      : tag(TypeTag::SYNTAX),
        type(s),
        size(size),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}

  std::string toString() const;
  std::string getTagString() const;
  std::string getTypeString() const;
};

#endif
