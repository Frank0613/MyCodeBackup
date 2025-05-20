#ifndef SmeltableOre_HPP
#define SmeltableOre_HPP

#include <string>
class SmeltableOre {
private:
  std::string smeltResult;

public:
  SmeltableOre(std::string result) { this->smeltResult = result; }
  virtual std::string Smelt() { return this->smeltResult; }
};
#endif
