#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player {
public:
  // Member
  std::string player_name = "player";
  int health = 3;
  bool alive = true;

  // Constructor
  Player(std::string player_name, int health, bool alive);
  ~Player();

  // Method
  std::string GetName();
  int GetHealth();
  bool IsAlive();
};

#endif