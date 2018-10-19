#include <SFML/Graphics.hpp>
#include <memory>

#include "Player.hpp"

class Game {
public:
    Game();
    ~Game();
    void start();

private:
  std::shared_ptr<sf::RenderWindow> m_window;
  std::shared_ptr<Player> m_player;
};