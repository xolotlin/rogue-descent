#ifndef WORLDRENDERER_H
#define WORLDRENDERER_H

#include "World.h"

struct SDL_Renderer;

class WorldRenderer {
public:
    void render(SDL_Renderer* renderer, const World& world) const;
};

#endif // WorldRenderer.h
