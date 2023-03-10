#pragma once
#include "Game.h"

class Object
{
public:
    Object();
    ~Object();
    void SetRect(const int &x, const int &y) { rect.x = x, rect.y = y; }
    SDL_Rect GetRect() const { return rect; }
    SDL_Texture *GetTexture() const { return texture; }

    bool LoadImg(string path, SDL_Renderer *gRenderer);
    void Render(SDL_Renderer *gRenderer, const SDL_Rect *clip = NULL);
    void Free();
    SDL_Texture *texture;
    SDL_Rect rect;
};