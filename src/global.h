#ifndef GLOBAL__
#define GLOBAL__

#define ROW 8
#define COLUMN 8
#define TERMINAL_MODE 2
extern unsigned char ulam_spiral[ROW][COLUMN];

// C headers
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Third party headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Project headers
#include "utils.h"
#include "ulam_spiral.h"
#include "init.h"
#include "sdl_ulam_spiral.h"

#endif