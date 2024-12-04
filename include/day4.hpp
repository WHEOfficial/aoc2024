#ifndef DAY3_HPP
#define DAY3_HPP

#include "common.hpp"
#include "day.hpp"

#include <string>
#include <regex>

class Day4 final : public IDay<int, int> {
  const int DIRS[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
  };

  std::vector<std::string> lines;
  size_t WIDTH, HEIGHT;

  bool findWord(const std::string& word, int x, int y, const int dir[2]) const {
    const int dx = dir[0];
    const int dy = dir[1];
    int i = 0;
    const size_t len = word.size();

    while (i < len) {
      x += dx, y += dy;

      if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return false;
      }

      if (lines[y].at(x) != word[i++]) {
        return false;
      }
    }

    return true;
  }

  bool findCross(int x, int y) const {
    switch (lines[y - 1].at(x - 1)) {
      case 'M': {
        switch (lines[y - 1].at(x + 1)) {
          case 'M': {
            return lines[y + 1].at(x - 1) == 'S' && lines[y + 1].at(x + 1) == 'S';
          }
          case 'S': {
            return lines[y + 1].at(x - 1) == 'M' && lines[y + 1].at(x + 1) == 'S';
          }
          default:
            return false;
        }
      }

      case 'S': {
        switch (lines[y - 1].at(x + 1)) {
          case 'S': {
            return lines[y + 1].at(x - 1) == 'M' && lines[y + 1].at(x + 1) == 'M';
          }
          case 'M': {
            return lines[y + 1].at(x - 1) == 'S' && lines[y + 1].at(x + 1) == 'M';
          }
          default:
            return false;
        }
      }
      default:
        return false;
    }
  }
public:
  explicit Day4(const char* inputFile) {
    FileHandler handler(inputFile);

    lines = handler.GetVector();

    WIDTH = lines[0].size();
    HEIGHT = lines.size();
  }

  int partOne() override {
    int occurrences = 0;

    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        if (const char c = lines[y].at(x); c == 'X') {
          for (const auto d : DIRS) {
            occurrences += findWord("MAS", x, y, d);
          }
        }
      }
    }

    return occurrences;
  }

  int partTwo() override {
    int occurrences = 0;

    for (int y = 1; y < HEIGHT - 1; y++) {
      for (int x = 1; x < WIDTH - 1; x++) {
        if (lines[y].at(x) == 'A') {
          occurrences += findCross(x, y);
        }
      }
    }

    return occurrences;
  }
};

#endif //DAY3_HPP
