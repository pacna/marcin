#include "global.h"

void process_input() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            default:
                break;
        }
    }
}

void load_text() {

    TTF_Font *arial = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 24);
    int rect_text_width = WINDOW_WIDTH;
    int rect_text_height = 60;
    int rect_text_x_center = rect_text_width /2; 

    if(!arial) {
        printf("Could not initialize font: %s\n", SDL_GetError());
    }

    SDL_Color green = {37, 193, 29};

    SDL_Rect message_rect;
    // center text in the middle of the screen
    message_rect.x = WINDOW_WIDTH/2 - rect_text_x_center; 
    message_rect.y = 0;
    message_rect.w = rect_text_width;
    message_rect.h = rect_text_height;

    unsigned char *text_message = "8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 * 0";

    SDL_Surface *surface_message = TTF_RenderText_Solid(arial, text_message, green);

    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_RenderFillRect(renderer, &message_rect);

    SDL_RenderCopy(renderer, message, NULL, &message_rect);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message);

    TTF_CloseFont(arial);
}

void render() {
    // color should look like the vs code monokai background color
    SDL_SetRenderDrawColor(renderer, 38, 41, 34, 1);
    SDL_RenderClear(renderer);
    load_text();
    SDL_RenderPresent(renderer);
}

void main_loop() {
    while(true) {
        process_input();
        render();
    }
}

void run_program() {
    main_loop();
}