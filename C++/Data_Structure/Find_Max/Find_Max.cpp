#include "Find_Max.hpp"
#include <iostream>

void FindMax(std::vector<int> list) {
  int max = list[0];
  for (int i = 1; i < list.size(); i++) {
    if (list[i] > max) {
      max = list[i];
    }
  }
  std::cout << max << std::endl;
};
