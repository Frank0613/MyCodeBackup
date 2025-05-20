#ifndef OOP_ORESTONE_H
#define OOP_ORESTONE_H

#include <string>
class OreStone {
public:
  virtual std::string GetOre() { return "Unknown Ore"; };
  virtual ~OreStone() {}
};

#endif
