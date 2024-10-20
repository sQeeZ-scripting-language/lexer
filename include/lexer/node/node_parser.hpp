#ifndef NODE_PARSER_HPP
#define NODE_PARSER_HPP

#include <napi.h>

#include "lexer/lexer.hpp"

Napi::Object tokenToJSObject(const Napi::Env& env, const Token& token);
Napi::Array vectorToJSArray(const Napi::Env& env, const std::vector<Token>& tokens);

#endif // NODE_PARSER_HPP