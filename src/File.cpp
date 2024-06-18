#include "File.h"

void File::advance() 
{
  if (currentChar() == '\n') {
    ++line;
    column = 0;
  }
  ++position;
  ++column;
}
