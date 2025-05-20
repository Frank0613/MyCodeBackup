#include <string>
class Character {
private:
  std::string name;
  int health;

public:
  Character(std::string name, int health);

  // Getter
  std::string GetName();
  int GetHealth();
  int GetLevel();

  // Setter
  std::string SetName();
  int SetHealth();
  int SetLevel();

protected:
  int level;
  int SkillUsageCount();
};