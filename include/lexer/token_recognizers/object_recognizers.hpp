#ifndef OBJECT_RECOGNIZERS_HPP
#define OBJECT_RECOGNIZERS_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = std::function<void(Lexer&, std::unique_ptr<Token>&)>;

void registerObjectRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif