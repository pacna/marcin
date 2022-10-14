#ifndef COLORS__
#define COLORS__

#define NUM_OF_RGBA 4
#define NUM_OF_COLOR_OPTIONS 5
#define TOTAL_COLOR_SIZE NUM_OF_RGBA *NUM_OF_COLOR_OPTIONS

typedef enum Color
{
    black,
    red,
    green,
    blue,
    white
} color_t;

extern SDL_Color get_sdl_rgba(color_t color_index);

#endif