#ifndef GAMELIBRARY_HPP
#define GAMELIBRARY_HPP

#include "Game.hpp"
#include <initializer_list>
#include <vector>
class GameLibrary {
public:
  GameLibrary(std::initializer_list<Game> games = {});
  ~GameLibrary();

  void AddGame(Game games);
  std::vector<Game> GetGames();

private:
  std::vector<Game> m_game;
};

#endif
