#ifndef COMMON_HPP
#define COMMON_HPP

#include <fstream>
#include <string>
#include <vector>

class FileHandler {
  std::vector<std::string> lines;
public:
  explicit FileHandler(const char* fileName) {
    std::ifstream stream(fileName);

    if (!stream) {
      throw std::invalid_argument("Couldn't open file");
    }

    std::string line;
    while (std::getline(stream, line)) {
      lines.push_back(line);
    }

    stream.close();
  }

  std::vector<std::string> GetVector() {return lines;}
};

#endif //COMMON_HPP
