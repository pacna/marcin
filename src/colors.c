#include "global.h"

static uint8_t colors[TOTAL_COLOR_SIZE] = {
    0, 0, 0, 255,       // BLACK
    200, 0, 0, 255,     // RED
    0, 200, 0, 255,     // GREEN
    0, 0, 200, 255,     // BLUE
    255, 255, 255, 255, // WHITE
};

SDL_Color get_sdl_rgba(color_t color_index)
{
    SDL_Color sdl_rgba;
    sdl_rgba.r = colors[(NUM_OF_RGBA * color_index) + 0];
    sdl_rgba.g = colors[(NUM_OF_RGBA * color_index) + 1];
    sdl_rgba.b = colors[(NUM_OF_RGBA * color_index) + 2];
    sdl_rgba.a = colors[(NUM_OF_RGBA * color_index) + 3];

    return sdl_rgba;
}