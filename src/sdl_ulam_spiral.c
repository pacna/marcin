#include "global.h"
#include "sdl_ulam_spiral.h"

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

void display_ulam_spiral(SDL_Renderer *renderer, int x_coordinate, int y_coordinate, char *ulam_output) {
    TTF_Font *arial = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 24);
    int rect_text_width = WINDOW_WIDTH;
    int rect_text_height = 60;

    if(!arial) {
        printf("Could not initialize font: %s\n", SDL_GetError());
    }

    SDL_Color green = {37, 193, 29};

    SDL_Rect message_rect;

    message_rect.x = x_coordinate; 
    message_rect.y = y_coordinate;
    message_rect.w = rect_text_width;
    message_rect.h = rect_text_height;

    SDL_Surface *surface_message = TTF_RenderText_Solid(arial, ulam_output, green);

    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_RenderFillRect(renderer, &message_rect);

    SDL_RenderCopy(renderer, message, NULL, &message_rect);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message);

    TTF_CloseFont(arial);
}

void render_ulam_spiral() {
    coordinate center = find_center(ROW, COLUMN);
    place_numbers_in_spiral(center, ulam_spiral);
    int y_position = 0;
    // # of elements in the array (ROW or COLUMN) * 2 (since we want spaces between possible _prime_number)
    char possible_characters_in_a_row[MAX_NUM_OF_DIGITS * (COLUMN * 2)];;
    char possible_prime_number[MAX_NUM_OF_DIGITS + 1];
    for(int i = 0; i< ROW; i++) {
        for (int j = 0; j< COLUMN; j++) {
            if (ulam_spiral[i][j] != '*') {
                // no need to create add space at the last possible_prime_number
                if (j == COLUMN - 1) {
                    sprintf(possible_prime_number, "%d", ulam_spiral[i][j]);
                } else {
                    sprintf(possible_prime_number, "%d ", ulam_spiral[i][j]);
                    // printf("%d",possible_prime_number[1]);
                }
            } 
            else {
                // no need to create add space at the last possible_prime_number
                if (j == COLUMN - 1) {
                    sprintf(possible_prime_number, "%c", ulam_spiral[i][j]);
                } else {
                    sprintf(possible_prime_number, "%c ", ulam_spiral[i][j]);
                }
            }

            strcat(possible_characters_in_a_row, possible_prime_number);
            // empty out possible_prime_number
            memset(possible_prime_number, 0, strlen(possible_prime_number));
        }
        display_ulam_spiral(renderer, 0, y_position, possible_characters_in_a_row);
        y_position+=60;
        // empty out possible_characters_in_a_row
        memset(possible_characters_in_a_row, 0, strlen(possible_characters_in_a_row));
    }
}

void render() {
    // color should look like the vs code monokai background color
    SDL_SetRenderDrawColor(renderer, 38, 41, 34, 1);
    SDL_RenderClear(renderer);
    render_ulam_spiral();
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