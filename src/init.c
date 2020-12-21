#include "global.h"

int init_SDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Could not initialize SDL \n");
        return -1;
    }

    return 1;
}

int init_window() {
    window = NULL;
    init_SDL();

    window = SDL_CreateWindow(
        "SDL Ulam Spiral",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (window == NULL) {
        printf("Could not initialize window: %s\n", SDL_GetError());
        return -1;
    }

    return 1;
}

int init_renderer() {
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Could not initialize renderer: %s\n", SDL_GetError());
        return -1;
    }

    return 1;
}

int init_TTF() {
    if (TTF_Init() == -1) {
        printf("Could not initialize TTF: %s\n", SDL_GetError());
        return -1;
    }
    
    return 1;
}

int init_sdl_ulam_spiral() {
    if (!init_window()) {
        return 0;
    }
    if (!init_renderer()) {
        return 0;
    }
    if (!init_TTF()) {
        return 0;
    }

    return 1;
}