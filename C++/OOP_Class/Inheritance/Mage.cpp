#include "Mage.hpp"

int Mage::GetAbilityPower() { return abilityPower; }

int Mage::SetAbilityPower(int abilityPower) {
  this->abilityPower = abilityPower;
}

void Mage::WizardLevelUp(int level) { this->level * 0.5f * abilityPower; }