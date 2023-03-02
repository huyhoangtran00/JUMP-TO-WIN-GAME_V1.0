#include "Game.h"
#include "Object.h"
class Map
{
public:
    Map();
    ~Map();
    void LoadTile(SDL_Renderer *gRenderer);
    void LoadMap();
    void DrawMap(SDL_Renderer *gRenderer, int offSetX);
    int tilemap[TILE_MAX_Y][TILE_MAX_X];
    SDL_Rect tile[TILE_MAX_Y][TILE_MAX_X];
    Object tile_texture[4];
};
