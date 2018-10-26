#include <SFML/Graphics.hpp>
#include <memory>

#include "Player.hpp"

class Game {
public:
  Game();
  ~Game();
  void Start();
  void UpdateGravity(bool left);
  sf::RectangleShape Ground(float width, float height, float x, float y);

private:
  std::shared_ptr<sf::RenderWindow> m_window;
  std::shared_ptr<b2Vec2> m_gravity;
  std::shared_ptr<b2World> m_world;
  std::shared_ptr<Player> m_player;
};