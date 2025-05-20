#include "Linear_Search.hpp"
#include <iostream>

int LinearSearch(int target, std::vector<int> targetList) {
  int index;
  int location;
  while (index <= targetList.size() && target != targetList[index]) {
    index += 1;
  }
  if (index <= targetList.size()) {
    location = index;
  } else {
    return -1;
  }
  std::cout << location;
  return location;
};