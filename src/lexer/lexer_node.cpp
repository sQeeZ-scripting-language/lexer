#include "lexer/lexer_node.hpp"

LexerNode::LexerNode(const Napi::CallbackInfo &args) : ObjectWrap(args) {
  this->_env = args.Env();
  if (args.Length() < 1 || !args[0].IsFunction()) {
    Napi::TypeError::New(this->_env, "Function expected").ThrowAsJavaScriptException();
  }
  Napi::Function require = args[0].As<Napi::Function>();
  std::regex self_regex("^function require\\(path\\)", std::regex_constants::ECMAScript | std::regex_constants::icase);
  if (!std::regex_search(require.ToString().Utf8Value().c_str(), self_regex)) {
    Napi::TypeError::New(this->_env, "{require} Function expected").ThrowAsJavaScriptException();
  }
  this->_require = Persistent(require);
}

Napi::String LexerNode::pingInstance(const Napi::CallbackInfo &args) {
  return Napi::String::New(this->_env, "Node instance of the sQeeZ-Lexer is working!");
}

Napi::String LexerNode::lex(const Napi::CallbackInfo &args) {
  if (args.Length() < 1 || !args[0].IsString()) {
    Napi::TypeError::New(this->_env, "Code expected!").ThrowAsJavaScriptException();
  }
  Napi::Env env = args.Env();
  auto code = args[0].As<Napi::String>().Utf8Value();
  Lexer lexer(code);
  std::string tmp = ""; 
  auto vector = lexer.lex();
  for (auto &token : vector) {
    tmp += token.desc + "\n";
  }
  return Napi::String::New(this->_env, "Received Code: " + tmp);
}

Napi::Function LexerNode::GetClass(Napi::Env env) {
  return DefineClass(env, "LexerNode", {
    LexerNode::InstanceMethod("pingInstance", reinterpret_cast<InstanceMethodCallback>(&LexerNode::pingInstance)),
    LexerNode::InstanceMethod("lex", reinterpret_cast<InstanceMethodCallback>(&LexerNode::lex))
  });
}

Napi::String pingLexer(const Napi::CallbackInfo &args) {
  Napi::Env env = args.Env();
  return Napi::String::New(env, "Node API for Lexer is working!");
}

Napi::String info(const Napi::CallbackInfo &args) {
  Napi::Env env = args.Env();
  std::string info = R"(
    sQeeZ-Lexer Node API Information:

    - Command Methods:
      1. info: Provides this API information.
      2. pingLexer: Pings the module to check if it's responsive.

    - Instance Methods:
      1. ping: Pings the lexer instance.
      2. lex: Processes and lexes a provided code snippet.
    )";
  return Napi::String::New(env, info);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "pingLexer"), Napi::Function::New(env, pingLexer));
  exports.Set(Napi::String::New(env, "info"), Napi::Function::New(env, info));
  Napi::String name = Napi::String::New(env, "LexerNode");
  exports.Set(name, LexerNode::GetClass(env));
  return exports;
}

NODE_API_MODULE(lexer, Init)