#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "File.h"
#include "Token.h"

#include <string>

std::vector<Token> tokenize(const std::string& input);

#endif
