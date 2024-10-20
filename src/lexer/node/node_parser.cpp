#include "lexer/node/node_parser.hpp"

Napi::Object tokenToJSObject(const Napi::Env& env, const Token& token) {
  Napi::Object jsToken = Napi::Object::New(env);
  jsToken.Set("tag", Napi::String::New(env, token.getTagString()));
  jsToken.Set("type", Napi::String::New(env, token.getTypeString()));
  jsToken.Set("size", Napi::Number::New(env, token.size));
  jsToken.Set("pos", Napi::Number::New(env, token.pos));
  jsToken.Set("value", Napi::String::New(env, token.value));
  jsToken.Set("plainText", Napi::String::New(env, token.plainText));
  jsToken.Set("desc", Napi::String::New(env, token.desc));
  return jsToken;
}

Napi::Array vectorToJSArray(const Napi::Env& env, const std::vector<Token>& tokens) {
  Napi::Array jsArray = Napi::Array::New(env, tokens.size());
  for (size_t i = 0; i < tokens.size(); ++i) {
    jsArray.Set(i, tokenToJSObject(env, tokens[i]));
  }
  return jsArray;
}
