#include "compiler.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string_view>
#include <optional>
#include <vector>

std::optional<std::string> getFileContents(std::string_view filePathString)
{
  std::filesystem::path filePath{filePathString};

  // Check if the file exists
  if (!std::filesystem::exists(filePath)) 
  {
    std::cerr << "File does not exist: " << filePath << std::endl;
    return std::nullopt;
  }

  // Open the file
  std::ifstream file(filePath);
  if (!file) 
  {
    std::cerr << "Failed to open the file: " << filePath << std::endl;
    return std::nullopt;
  }

  // Read the contents of the file
  std::string line;
  std::stringstream ss;
  while (std::getline(file, line)) 
  {
    ss << line << '\n';
  }

  return ss.str();
}

int main(int argc, const char* argv[])
{
  if(argc != 2)
  {
    std::cerr << "Must give file to compile";
    return 1;
  }

  if(auto result = getFileContents(argv[1]))
  {
    auto tokens = tokenize(result.value());
  }

  return 0;
}
