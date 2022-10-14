#include "global.h"

SDL_Window *window;
SDL_Renderer *renderer;

unsigned char ulam_spiral[ROW][COLUMN] = {'\0'};

bool is_sdl_mode(char *input)
{
    return input == NULL || strcmp(SDL_MODE, input) == 0;
}

bool is_terminal_mode(char *input)
{
    return strcmp(TERMINAL_MODE, input) == 0;
}