#include "Player.hpp"
#include <iostream>

Player::Player(std::shared_ptr<b2World> world)
{
    m_x_vel = 0.f;
    m_y_vel = 0.f;

    m_game_object = new GameObject(sf::Color::Green, 50.f, 50.f, 200.f, -50.f, world);
}

Player::~Player()
{}

void Player::Update(float delta_time, std::shared_ptr<sf::RenderWindow>& window) {
    m_game_object->Update(delta_time, window);
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