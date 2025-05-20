#include "Player.hpp"

Player::Player(std::string player_name, int health, bool alive) {
  if (health <= 0) {
    throw std::string("Invalid Health");
  }
  this->player_name = player_name;
  this->health = health;
  this->alive = alive;
}

Player::~Player() {}

std::string Player::GetName() { return player_name; }

int Player::GetHealth() { return health; }

bool Player::IsAlive() { return alive; }
