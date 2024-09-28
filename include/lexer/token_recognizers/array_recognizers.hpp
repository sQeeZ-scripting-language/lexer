#ifndef ARRAY_RECOGNIZERS_HPP
#define ARRAY_RECOGNIZERS_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "lexer/lexer.hpp"

using TokenRecognizer = std::function<void(Lexer&, std::unique_ptr<Token>&)>;

void recognizePush(Lexer& lexer, std::unique_ptr<Token>& tokenPtr);

void registerArrayRecognizers(std::unordered_map<std::string, TokenRecognizer>& tokenRecognizers);

#endif