#include "GameLibrary.hpp"
#include <initializer_list>

GameLibrary::GameLibrary(std::initializer_list<Game> games) { m_game = games; }

void GameLibrary::AddGame(Game games) { m_game.push_back(games); }

std::vector<Game> GameLibrary::GetGames() { return m_game; }
