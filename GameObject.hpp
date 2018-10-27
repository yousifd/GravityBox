#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>

class GameObject {
public:
  GameObject(sf::Color color, float width, float height, float x, float y,
             bool dynamic, b2World &world);
  ~GameObject();

  void Update(float delta_time, sf::RenderWindow &window);

private:
  float m_scale;

  // Rendering Info
  sf::RectangleShape m_sprite;

  // Physics Info
  b2BodyDef m_body_def;
  b2PolygonShape m_shape;
  b2FixtureDef m_fixture_def;
  b2Body* m_body;
};

#endif // GAMEOBJECT_H_