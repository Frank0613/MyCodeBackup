#include "GoldOre.hpp"
#include "IronOre.hpp"
#include "SmeltableOre.hpp"
#include <vector>
class QueueFurnace {
private:
  int index;
  std::vector<SmeltableOre *> oreQueue;

public:
  QueueFurnace() = default;
  void AddOre(SmeltableOre *ore) { oreQueue.push_back(ore); }
  std::string SmeltItem() {
    std::string result = "";
    if (index == oreQueue.size()) {
      return result;
    }
    result = oreQueue[index]->Smelt();
    index++;
    return result;
  }
};