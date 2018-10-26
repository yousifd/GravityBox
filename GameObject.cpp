#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(sf::Color color, float width, float height, float x, float y,
                       std::shared_ptr<b2World> world)
{
    m_scale = 30.0f;
    sf::Vector2f size(width, height);
    m_sprite = std::make_shared<sf::RectangleShape>(size);
    m_sprite->setOrigin(size.x / 2, size.y / 2);
    m_sprite->setFillColor(color);

    m_body_def.type = b2_dynamicBody;
    m_body_def.allowSleep = false;
    m_body_def.position.Set(x, y);

    m_dynamic_box.SetAsBox(width / 2.f, height / 2.f);

    m_fixture_def.shape = &m_dynamic_box;
    m_fixture_def.density = 1.0f;
    m_fixture_def.friction = 0.3f;

    m_body = world->CreateBody(&m_body_def);
    m_body->CreateFixture(&m_fixture_def);
}

GameObject::~GameObject() {

}

void GameObject::Update(float delta_time, std::shared_ptr<sf::RenderWindow> &window)
{
    b2Vec2 pos = m_body->GetPosition();
    m_sprite->setPosition(pos.x, -pos.y);
    m_sprite->setRotation(180/b2_pi * m_body->GetAngle());
    window->draw(*m_sprite);
}