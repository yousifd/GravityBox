#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>

#include "GameObject.hpp"

class Player {
public:
  Player(std::shared_ptr<b2World> world);
  ~Player();
  void SetXVelocity(float x);
  void SetYVelocity(float y);
  void SetVelocity(float x, float y);
  void Update(float delta_time, std::shared_ptr<sf::RenderWindow> &window);

private:  
  GameObject* m_game_object;
};