#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include "data_tokens.hpp"
#include "error_tokens.hpp"
#include "keyword_tokens.hpp"
#include "log_tokens.hpp"
#include "logical_tokens.hpp"
#include "operator_tokens.hpp"
#include "syntax_tokens.hpp"

enum class BasicToken { TOKEN_EOF, UNKNOWN };

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

  std::string value;
  std::string desc;

  Token(BasicToken b, std::string value = "", std::string desc = "")
      : tag(TypeTag::BASIC), type(b), value(std::move(value)), desc(std::move(desc)) {}
  Token(DataToken d, std::string value = "", std::string desc = "")
      : tag(TypeTag::DATA), type(d), value(std::move(value)), desc(std::move(desc)) {}
  Token(ErrorToken e, std::string value = "", std::string desc = "")
      : tag(TypeTag::ERROR), type(e), value(std::move(value)), desc(std::move(desc)) {}
  Token(KeywordToken k, std::string value = "", std::string desc = "")
      : tag(TypeTag::KEYWORD), type(k), value(std::move(value)), desc(std::move(desc)) {}
  Token(LogToken l, std::string value = "", std::string desc = "")
      : tag(TypeTag::LOG), type(l), value(std::move(value)), desc(std::move(desc)) {}
  Token(LogicalToken l, std::string value = "", std::string desc = "")
      : tag(TypeTag::LOGICAL), type(l), value(std::move(value)), desc(std::move(desc)) {}
  Token(OperatorToken o, std::string value = "", std::string desc = "")
      : tag(TypeTag::OPERATOR), type(o), value(std::move(value)), desc(std::move(desc)) {}
  Token(SyntaxToken s, std::string value = "", std::string desc = "")
      : tag(TypeTag::SYNTAX), type(s), value(std::move(value)), desc(std::move(desc)) {}
};

#endif
