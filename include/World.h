#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"

#include <vector> 

class World {
public:
    int width, height;
    float tileSize; // grid columns, rows (depth)
    std::vector<Tile> tiles;

    World(int width, int height, float tileSize);

    void generate();

    Tile& getTile(int x, int y);
    const Tile& getTile(int x, int y) const;
    bool inBounds(int x, int y) const;
};

#endif // World_h