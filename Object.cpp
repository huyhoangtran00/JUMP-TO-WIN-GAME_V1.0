#include "Object.h"

Object::Object()
{
    texture = NULL;
    rect = {0, 0, 0, 0};
}

Object::~Object()
{
    Free();
}

bool Object::LoadImg(string path, SDL_Renderer *gRenderer)
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *load_surface = IMG_Load(path.c_str());
    if (load_surface != NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, 255, 255, 255));
        newTexture = SDL_CreateTextureFromSurface(gRenderer, load_surface);
        if (newTexture != NULL)
        {
            rect.w = load_surface->w;
            rect.h = load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
    texture = newTexture;
    return texture != NULL;
}

void Object::Render(SDL_Renderer *gRenderer, const SDL_Rect *clip)
{
    SDL_Rect renderquad = {rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopy(gRenderer, texture, clip, &renderquad);
}
void Object::Free()
{
    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        rect.w = 0;
        rect.h = 0;
    }
}