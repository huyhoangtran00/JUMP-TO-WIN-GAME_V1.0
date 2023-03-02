#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace std;

static SDL_Renderer *gRenderer = NULL;
static SDL_Window *gWindow = NULL;
static SDL_Event event;
static int offSetY = 15;

#define TILE_MAX_X 20
#define TILE_MAX_Y 30
#define TILE_SIZE_W 32
#define TILE_SIZE_H 32
