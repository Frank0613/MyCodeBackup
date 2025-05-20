#include "Character.hpp"

class Mage : public Character {
private:
  int abilityPower;

public:
  Mage(int abilityPower, std::string name, int health);

  int GetAbilityPower();
  int SetAbilityPower(int abilityPower);
  virtual void WizardLevelUp(int level) = 0;
};