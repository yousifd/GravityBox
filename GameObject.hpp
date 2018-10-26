#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>

class GameObject {
public:
  GameObject(sf::Color color, float width, float height, float x, float y,
             std::shared_ptr<b2World> world);
  ~GameObject();

  void Update(float delta_time, std::shared_ptr<sf::RenderWindow> &window);

private:
  float m_scale;

  // Rendering Info
  std::shared_ptr<sf::RectangleShape> m_sprite;

  // Physics Info
  b2BodyDef m_body_def;
  b2PolygonShape m_dynamic_box;
  b2FixtureDef m_fixture_def;
  b2Body* m_body;
};