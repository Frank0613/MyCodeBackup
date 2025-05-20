#include "Ahri.hpp"
#include <string>

Character::Character(std::string name, int health) {
  this->name = name;
  this->health = health;
}

Mage::Mage(int abilityPower, std::string name, int health)
    : Character(name, health) {
  this->abilityPower = abilityPower;
}

Ahri::Ahri(int abilityPower, std::string name, int health)
    : Mage(abilityPower, name, health) {
  GetHealth();

  // Ahri
}