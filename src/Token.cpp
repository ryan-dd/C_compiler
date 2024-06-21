#include "Token.h"

bool isType(TokenType tokenType)
{
  switch(tokenType)
  {
    case TokenType::Int:
    case TokenType::Void:
      return true;
    default:
      return false;
  }
}
