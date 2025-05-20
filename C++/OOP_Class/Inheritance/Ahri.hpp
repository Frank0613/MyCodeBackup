#include "Mage.hpp"
#include <string>

class Ahri final : public Mage {
public:
  Ahri(int abilityPower, std::string name, int health);
  // Ahri-Only
  void OrbOfDescription();
  void FoxFire();
  void Charm();
  void SpiritRush();

  virtual void WizardLevelUp(int level) override;
};