
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType 
{
  Identifier,
  Int,
  Void,
  LeftBrace,
  RightBrace,
  LeftParen,
  RightParen,
  LeftBracket,
  RightBracket,
  Semicolon,
  Comma,
  Return,
  IntegerLiteral,
  EndOfFile
};

bool isType(TokenType tokenType);

struct Token
{
  TokenType type;
  std::string value;
  int line;
  int column;

  bool operator==(const Token&) const = default;
};

#endif
