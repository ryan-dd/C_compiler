#ifndef AST_NODE_H
#define AST_NODE_H

#include "Token.h"

#include <vector>

struct FunctionParameter
{
  Token type;
  Token identifier;
};

struct Statement
{

};

struct FunctionNode
{
  Token returnType;
  Token identifier;
  std::vector<FunctionParameter> parameters;
  std::vector<Statement> body;
};

struct Program
{
  std::vector<FunctionNode> functions;
};

#endif
