#ifndef OOP_REDORESTONE_H
#define OOP_REDORESTONE_H

#include "OreStone.hpp"
#include <string>
class RedOreStone : public OreStone {
public:
  std::string GetOre() override { return "Red Stone"; }
  void ShineStoneTexture();
  ~RedOreStone() override {}
};

#endif
