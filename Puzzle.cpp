#include "Puzzle.hpp"

Puzzle::Puzzle(int width, int height, b2World &world) {
    Generate(width, height, world);
}

Puzzle::~Puzzle() {
}

void Puzzle::Update(float delta_time, sf::RenderWindow &window) {
    for (auto x : m_tiles) {
        for (auto y : x) {
            y.Update(delta_time, window);
        }
    }
}

void Puzzle::Generate(int width, int height, b2World &world) {
    for (int x = 0; x < width; x++) {
        m_tiles.push_back(std::vector<Tile>());
        for (int y = 0; y < height; y++) {
            m_tiles[x].push_back(Tile(x * (1280/width), y * (720/height), world));
        }
    }
}