#include "Tile.hpp"

Tile::Tile(float x, float y, b2World &world) {
    for (int i = 0; i < 4; i++) {
        m_walls[i] = rand() % 2 == 0 ? new GameObject(sf::Color::White, 10, 100, x, y, false, world) : nullptr;
    }
}

Tile::~Tile() {
}

void Tile::Update(float delta_time, sf::RenderWindow &window) {
    for (int i = 0; i < 4; i++) {
        if (m_walls[i] != nullptr) {
            m_walls[i]->Update(delta_time, window);
        }
    }
}