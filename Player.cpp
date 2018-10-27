#include "Player.hpp"

Player::Player(b2World &world) {
    m_game_object = new GameObject(sf::Color::Green, 50.f, 50.f, 200.f, 50.f, true, world);
}

Player::~Player() {
}

sf::Vector2f Player::GetPosition() {
    return m_game_object->GetPosition();
}

void Player::Update(float delta_time, sf::RenderWindow &window) {
    m_game_object->Update(delta_time, window);
}