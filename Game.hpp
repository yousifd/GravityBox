#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <memory>

#include "Player.hpp"

class Game {
public:
  Game();
  ~Game();
  void Start();
  void UpdateGravity(bool left);

private:
  const float m_gravity_vel = -0.5f;
  std::shared_ptr<sf::RenderWindow> m_window;
  std::shared_ptr<b2Vec2> m_gravity;
  std::shared_ptr<b2World> m_world;
  std::shared_ptr<Player> m_player;
};

#endif // GAME_H_