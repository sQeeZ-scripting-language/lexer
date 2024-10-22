#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <sstream>
#include <string>

#include "data_tokens.hpp"
#include "keyword_tokens.hpp"
#include "log_tokens.hpp"
#include "logical_tokens.hpp"
#include "operator_tokens.hpp"
#include "short_notation_tokens.hpp"
#include "syntax_tokens.hpp"

enum class BasicToken { INIT, TOKEN_EOF, UNKNOWN };

struct Token {
  enum class TypeTag { BASIC, DATA, KEYWORD, LOG, LOGICAL, OPERATOR, SHORT_NOTATION, SYNTAX } tag;

  union TokenType {
    BasicToken basicToken;
    DataToken dataToken;
    KeywordToken keywordToken;
    LogToken logToken;
    LogicalToken logicalToken;
    OperatorToken operatorToken;
    ShortNotationToken shortNotationToken;
    SyntaxToken syntaxToken;

    TokenType() {}
    TokenType(BasicToken t) : basicToken(t) {}
    TokenType(DataToken t) : dataToken(t) {}
    TokenType(KeywordToken t) : keywordToken(t) {}
    TokenType(LogToken t) : logToken(t) {}
    TokenType(LogicalToken t) : logicalToken(t) {}
    TokenType(OperatorToken t) : operatorToken(t) {}
    TokenType(ShortNotationToken t) : shortNotationToken(t) {}
    TokenType(SyntaxToken t) : syntaxToken(t) {}
  } type;

  size_t size;
  size_t pos;
  std::string value;
  std::string plainText;
  std::string desc;

  Token(BasicToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::BASIC),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(DataToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::DATA),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(KeywordToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::KEYWORD),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(LogToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::LOG),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(LogicalToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::LOGICAL),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(OperatorToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::OPERATOR),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(ShortNotationToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::SHORT_NOTATION),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}
  Token(SyntaxToken token, size_t size = 0, size_t pos = 0, std::string value = "", std::string plainText = "",
        std::string desc = "")
      : tag(TypeTag::SYNTAX),
        type(token),
        size(size),
        pos(pos),
        value(std::move(value)),
        plainText(std::move(plainText)),
        desc(std::move(desc)) {}

  std::string toString() const;
  std::string getTagString() const;
  std::string getTypeString() const;
};

#endif  // TOKEN_HPP
