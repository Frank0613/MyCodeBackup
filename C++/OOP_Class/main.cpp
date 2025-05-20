
#include "Player\Player.cpp"
#include "Polymorphism\Object Casting\OreStone.hpp"
#include "Polymorphism\Object Casting\RedOreStone.hpp"
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<OreStone> stone = std::make_shared<RedOreStone>();
  std::cout << stone->GetOre() << std::endl;
}
