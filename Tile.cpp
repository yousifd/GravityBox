#include <cstdlib>

#include "Tile.hpp"

Tile::Tile(float x, float y, b2World &world) {
    // TODO(yousifd): Figure out dimensions of each wall
    // Top
    m_walls[0] = rand() % 2 == 0 ? new GameObject(sf::Color::White, 128, 10, x, y, false, world) : nullptr;
    // Right
    m_walls[1] = rand() % 2 == 0 ? new GameObject(sf::Color::White, 10, 128, x+64, y+64, false, world) : nullptr;
    // Bottom
    m_walls[2] = rand() % 2 == 0 ? new GameObject(sf::Color::White, 128, 10, x, y+128, false, world) : nullptr;
    // Left
    m_walls[3] = rand() % 2 == 0 ? new GameObject(sf::Color::White, 10, 128, x-64, y+64, false, world) : nullptr;
}

Tile::~Tile() {
    for (int i = 0; i < 4; i++) {
        delete m_walls[i];
    }
}

void Tile::Update(float delta_time, sf::RenderWindow &window) {
    for (int i = 0; i < 4; i++) {
        if (m_walls[i] != nullptr) {
            m_walls[i]->Update(delta_time, window);
        }
    }
}