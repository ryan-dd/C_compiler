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
  Return,
  IntegerLiteral
};

struct Token
{
  TokenType type;
  std::string value;
  int line;
  int column;

  bool operator==(const Token&) const = default;
};
