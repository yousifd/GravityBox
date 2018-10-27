#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>
#include <array>

#include "GameObject.hpp"

class Tile {
public:
    Tile(float x, float y, b2World &world);
    ~Tile();
    void Update(float delta_time, sf::RenderWindow &window);
private:
    std::array<GameObject*, 4> m_walls;
};

#endif // TILE_H_