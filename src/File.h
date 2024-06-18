#include <string>

class File 
{
private:
  std::string source{};
  size_t position{};
  int line{};
  int column{};
public:
  explicit File(const std::string& input): source(input){}
  int getLine(){return line;}
  int getColumn(){return column;}

  char currentChar() const {
      return position < source.size() ? source[position] : '\0';
  }

  void advance(); 
};
