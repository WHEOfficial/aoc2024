#include <iostream>
#include <chrono>

#include "day4.hpp"

namespace sc = std::chrono;

int main() {
  const auto inputFile = "../input/day4.txt";
  const auto start = sc::high_resolution_clock::now();

  Day4 day(inputFile);

  const auto initTime = sc::high_resolution_clock::now();

  int result = day.partOne();

  std::cout << "Part 1: " << result << std::endl;

  const auto partOneTime = sc::high_resolution_clock::now();

  result = day.partTwo();

  std::cout << "Part 2: " << result << std::endl;

  const auto partTwoTime = sc::high_resolution_clock::now();

  const auto initDuration = sc::duration_cast<sc::milliseconds>(initTime - start);
  const auto partOneDuration = sc::duration_cast<sc::milliseconds>(partOneTime - initTime);
  const auto partTwoDuration = sc::duration_cast<sc::milliseconds>(partTwoTime - partOneTime);
  const auto totalDuration = sc::duration_cast<sc::milliseconds>(partTwoTime - start);

  std::cout << "\nInit: " << initDuration << ", P1: " << partOneDuration <<
    ", P2: " << partTwoDuration << std::endl;
  std::cout << "TOTAL: " << totalDuration << std::endl;
}
