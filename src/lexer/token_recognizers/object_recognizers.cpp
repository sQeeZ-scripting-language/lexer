#include "lexer/token_recognizers/object_recognizers.hpp"

void recognizeEntries(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
    if (lexer.checkKeyword("entries")) {
        tokenPtr = std::make_unique<Token>(ObjectToken::ENTRIES, 7, "entries", "ObjectToken::ENTRIES", "Get key-value pairs of an object");
    }
}

void recognizeKeys(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
    if (lexer.checkKeyword("keys")) {
        tokenPtr = std::make_unique<Token>(ObjectToken::KEYS, 4, "keys", "ObjectToken::KEYS", "Get keys of an object");
    }
}

void recognizeValues(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
    if (lexer.checkKeyword("values")) {
        tokenPtr = std::make_unique<Token>(ObjectToken::VALUES, 6, "values", "ObjectToken::VALUES", "Get values of an object");
    }
}

void recognizeHasOwnProperty(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
    if (lexer.checkKeyword("hasOwnProperty")) {
        tokenPtr = std::make_unique<Token>(ObjectToken::HAS_OWN_PROPERTY, 14, "hasOwnProperty", "ObjectToken::HAS_OWN_PROPERTY", "Check if an object has a property");
    }
}

void recognizeDelete(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
    if (lexer.checkKeyword("delete")) {
        tokenPtr = std::make_unique<Token>(ObjectToken::DELETE, 6, "delete", "ObjectToken::DELETE", "Delete a property from an object");
    }
}

void recognizeTypeOf(Lexer& lexer, std::unique_ptr<Token>& tokenPtr) {
    if (lexer.checkKeyword("typeof")) {
        tokenPtr = std::make_unique<Token>(ObjectToken::TYPE_OF, 6, "typeof", "ObjectToken::TYPE_OF", "Get the type of an object");
    }
}

void registerObjectRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers) {
    tokenRecognizers["entries"] = recognizeEntries;
    tokenRecognizers["keys"] = recognizeKeys;
    tokenRecognizers["values"] = recognizeValues;
    tokenRecognizers["hasOwnProperty"] = recognizeHasOwnProperty;
    tokenRecognizers["delete"] = recognizeDelete;
    tokenRecognizers["typeof"] = recognizeTypeOf;
}