#include "Map.h"
#include <stdio.h>
Map::Map()
{
}
Map::~Map() {}

void Map::LoadTile(SDL_Renderer *gRenderer)
{
    tile_texture[0].LoadImg("img/dark.png", gRenderer);
    tile_texture[1].LoadImg("img/dark.png", gRenderer);
    tile_texture[2].LoadImg("img/green.png", gRenderer);
    tile_texture[3].LoadImg("img/green.png", gRenderer);
    for (int i = 0; i < 4; i++)
    {

        tile_texture[i].rect = {0,
                                0,
                                16,
                                16};
    }
}

void Map::LoadMap()
{

    FILE *fp;
    fp = freopen("map.txt", "r", stdin);

    for (int i = 0; i < TILE_MAX_Y; i++)
    {
        for (int j = 0; j < TILE_MAX_X; j++)
        {
            int x;
            cin >> x;
            tilemap[i][j] = x;
        }
        cout << endl;
    }
    fclose(fp);

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            tile[i][j] = {j * 32, i * 32, 32, 32};
        }
        cout << endl;
    }
}
void Map::DrawMap(SDL_Renderer *gRenderer, int offSetY)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            switch ((tilemap[i + offSetY][j]))
            {
            case 0:

                break;
            case 1:
                tile_texture[1].rect = tile[i][j];
                tile_texture[1].Render(gRenderer, NULL);
                break;
            case 2:
                tile_texture[2].rect = tile[i][j];
                tile_texture[2].Render(gRenderer, NULL);
                break;

            default:
                break;
            }
        }
    }
}