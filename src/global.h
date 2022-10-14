#ifndef GLOBAL__
#define GLOBAL__

#define ROW 8
#define COLUMN 8

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

// Project headers
#include "utils.h"
#include "ulam_spiral.h"
#include "init.h"
#include "sdl_ulam_spiral.h"
#include "terminal_ulam_spiral.h"
#include "colors.h"
#include "log.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

#define SDL_MODE "sdl"
#define TERMINAL_MODE "terminal"

extern unsigned char ulam_spiral[ROW][COLUMN];
extern bool is_sdl_mode(char *input);
extern bool is_terminal_mode(char *input);

#endif