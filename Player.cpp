#include "Player.hpp"
#include <iostream>

Player::Player(std::shared_ptr<b2World> world)
{
    m_game_object = new GameObject(sf::Color::Green, 50.f, 50.f, 200.f, 50.f, true, world);
}

Player::~Player()
{}

void Player::Update(float delta_time, std::shared_ptr<sf::RenderWindow>& window) {
    m_game_object->Update(delta_time, window);
}