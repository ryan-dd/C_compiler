#ifndef PARSER_H
#define PARSER_H

#include "AST_Node.h"
#include "Token.h"

class Tokens
{
public:
  explicit Tokens(const std::vector<Token>& tokens) : tokens{tokens}{}
  Token currentToken() const {
      return position < tokens.size() ? 
        tokens[position] : 
        Token{
          .type = TokenType::EndOfFile,
          .value = "",
          .line = 0,
          .column = 0
        };
  }

  void advance()
  {
    position += 1;
  }

private:
  const std::vector<Token>& tokens;
  std::size_t position{0};
  
};

Program parse(const std::vector<Token>& tokens);

#endif
