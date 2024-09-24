#ifndef LEXER_NODE_HPP
#define LEXER_NODE_HPP

#include <napi.h>

class DemoClass : public Napi::ObjectWrap<DemoClass> {
private:
    Napi::FunctionReference _require;
    Napi::Env _env = Napi::Env(nullptr);

public:
    explicit DemoClass(const Napi::CallbackInfo &args);

    Napi::String sayHi(const Napi::CallbackInfo &args);

    Napi::Buffer<char> stringToBuffer(const Napi::CallbackInfo &args);

    Napi::Buffer<char> cryptoRandomBytes(const Napi::CallbackInfo &args);

    static Napi::Function GetClass(Napi::Env);
};

#endif