#include <SFML/Graphics.hpp>
#include <memory>

class Player
{
  public:
    Player();
    ~Player();
    void SetXVelocity(float x);
    void SetYVelocity(float y);
    void SetVelocity(float x, float y);
    void Update(float deltaTime, std::shared_ptr<sf::RenderWindow>& window);

  private:
    float m_x_vel;
    float m_y_vel;
    float m_max_vel;
    std::shared_ptr<sf::RectangleShape> m_sprite;
};