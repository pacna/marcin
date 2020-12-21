#ifndef _GLOBAL
#define _GLOBAL

#define ROW 5
#define COLUMN 5

extern unsigned char ulam_spiral[ROW][COLUMN];

// C header
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// third party header
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;

// custom header
#include "utils.h"
#include "spiral.h"
#include "init.h"

#endif