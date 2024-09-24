#ifndef LEXER_NODE_HPP
#define LEXER_NODE_HPP

#include <napi.h>
#include <regex>
#include <iostream>

Napi::String pingLexer(const Napi::CallbackInfo &args);

class LexerNode : public Napi::ObjectWrap<LexerNode> {
private:
    Napi::FunctionReference _require;
    Napi::Env _env = Napi::Env(nullptr);

public:
    explicit LexerNode(const Napi::CallbackInfo &args);

    Napi::String pingInstance(const Napi::CallbackInfo &args);

    static Napi::Function GetClass(Napi::Env);
};

#endif