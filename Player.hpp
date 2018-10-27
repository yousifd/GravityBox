#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "GameObject.hpp"

class Player {
public:
  Player(b2World &world);
  ~Player();
  void Update(float delta_time, sf::RenderWindow &window);
  sf::Vector2f GetPosition();

private:  
  GameObject *m_game_object;
};

#endif // PLAYER_H_