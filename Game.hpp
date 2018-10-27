#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Puzzle.hpp"

class Game {
public:
  Game();
  ~Game();
  void Start();

private:
  void UpdateGravityLeft();
  void UpdateGravityRight();

  const float m_gravity_vel = -0.2f;
  bool m_gravity_updated;
  sf::RenderWindow m_window;
  b2Vec2 m_gravity;
  b2World m_world;
  Player m_player;

  Puzzle m_puzzle;
};

#endif // GAME_H_