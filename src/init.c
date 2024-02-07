#include "global.h"

/**
 *  --- Private Functions ---
 **/
static int init_SDL(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        log_error_with_added_text("Could not initialize SDL: ", SDL_GetError());
        return -1;
    }

    return 1;
}

static int init_window(void)
{
    window = NULL;
    init_SDL();

    window = SDL_CreateWindow(
        "Marcin",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        log_error_with_added_text("Could not initialize window: ", SDL_GetError());
        return -1;
    }

    return 1;
}

static int init_renderer(void)
{
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        log_error_with_added_text("Could not initialize renderer: ", SDL_GetError());
        return -1;
    }

    return 1;
}

static int init_TTF(void)
{
    if (TTF_Init() == -1)
    {
        log_error_with_added_text("Could not initialize TTF: ", SDL_GetError());
        return -1;
    }

    return 1;
}

/**
 *  --- Public Functions ---
 **/
int init_sdl_ulam_spiral(void)
{
    if (!init_window())
    {
        return 0;
    }
    if (!init_renderer())
    {
        return 0;
    }
    if (!init_TTF())
    {
        return 0;
    }

    return 1;
}