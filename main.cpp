
#include "Game.h"
#include "Object.h"
#include "Map.h"
Object background;
Map map;
bool init();
void loadMedia();
bool loadBK();
int main(int argc, char *argv[])
{
    if (!init())
        return -1;
    if (!loadBK())
        return -1;

    loadMedia();
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_UP)
                {
                    offSetY--;
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    offSetY++;
                }
                if (offSetY < 0)
                    offSetY = 0;
                if (offSetY > 15)
                {
                    offSetY = 15;
                }
            }
        }
        SDL_RenderClear(gRenderer);
        SDL_SetRenderDrawColor(gRenderer, 255, 100, 255, 255);
        background.Render(gRenderer, NULL);
        map.DrawMap(gRenderer, offSetY);
        SDL_RenderPresent(gRenderer);
    }

    return 0;
}

bool init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window
        gWindow = SDL_CreateWindow("Snake MEME V2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

void loadMedia()
{
    map.LoadTile(gRenderer);
    map.LoadMap();
}
bool loadBK()
{
    bool ret = background.LoadImg("img/background.png", gRenderer);
    background.rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    if (ret == false)
        return false;
    return true;
}