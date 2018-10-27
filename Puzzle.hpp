#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Tile.hpp"

class Puzzle {
public:
    Puzzle(int width, int height, b2World &world);
    ~Puzzle();
    void Update(float delta_time, sf::RenderWindow &window);

private:
    void Generate(int width, int height, b2World &world);

    std::vector<std::vector<Tile>> m_tiles;
};

#endif // PUZZLE_H_