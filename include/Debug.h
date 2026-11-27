#ifndef DEBUG_H
#define DEBUG_H

#include "World.h"

class DebugUI {
public:
    bool visible = false;
    TileType selectedTileType = TileType::Wall;

    void render(World& world);
};

#endif // Debug_h