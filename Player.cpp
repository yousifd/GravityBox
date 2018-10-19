#include "Player.hpp"

Player::Player() {
    m_x_vel = 0.f;
    m_y_vel = 0.f;
    m_max_vel = 0.25f;

    sf::Vector2f size(50.f, 50.f);
    m_sprite = std::make_shared<sf::RectangleShape>(size);
    m_sprite->setFillColor(sf::Color::Green);
}

Player::~Player()
{}

void Player::Update(float deltaTime, std::shared_ptr<sf::RenderWindow>& window) {
    m_sprite->move(m_x_vel, m_y_vel);
    window->draw(*m_sprite);
}

void Player::SetXVelocity(float x) {
    m_x_vel += x;
}

void Player::SetYVelocity(float y) {
    m_y_vel += y;
}

void Player::SetVelocity(float x, float y) {
    SetXVelocity(x);
    SetYVelocity(y);
}