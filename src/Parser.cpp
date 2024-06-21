
#include "Parser.h"
#include "AST_Node.h"
#include <stdexcept>

void failIfNotType(Tokens& tokens, TokenType type)
{
  if (tokens.currentToken().type != type)
  {
    throw std::runtime_error{"Failed to parse" + tokens.currentToken().value};
  }
}

FunctionNode parseFunction(Tokens& tokens)
{
  if(!isType(tokens.currentToken().type))
  {
    throw std::runtime_error{"Function must start with type"};
  }

  FunctionNode function;
  function.returnType = tokens.currentToken();

  tokens.advance();
  failIfNotType(tokens, TokenType::Identifier);
  function.identifier = tokens.currentToken();

  tokens.advance();
  failIfNotType(tokens, TokenType::LeftParen);
  tokens.advance();

  while(isType(tokens.currentToken().type))
  {
    FunctionParameter parameter;
    parameter.type = tokens.currentToken();

    tokens.advance();
    failIfNotType(tokens, TokenType::Identifier); // Require an identifier for now
    parameter.identifier = tokens.currentToken();
    function.parameters.push_back(parameter);

    tokens.advance();
    if(tokens.currentToken().type != TokenType::Comma)
    {
      break;
    }

    tokens.advance();
  }

  failIfNotType(tokens, TokenType::RightParen);
  tokens.advance();
  failIfNotType(tokens, TokenType::LeftBrace);

  while(tokens.currentToken().type != TokenType::RightBrace &&
        tokens.currentToken().type != TokenType::EndOfFile)
  {
    tokens.advance();
    // parse body of function
  }

  tokens.advance();

  return function;
}

Program parse(const std::vector<Token>& inputTokens)
{
  Tokens tokens{inputTokens};

  Program rootNode;

  while(tokens.currentToken().type != TokenType::EndOfFile)
  {
    rootNode.functions.push_back(parseFunction(tokens));
  }

  return rootNode;
}
