#include "global.h"

/**
 *  --- Private Functions ---
 **/
static void process_input(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        default:
            break;
        }
    }
}

static void display_ulam_spiral(SDL_Renderer *renderer, int x_coordinate, int y_coordinate, char *ulam_output)
{
    TTF_Font *open_sans = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 60);
    int rect_text_width = WINDOW_WIDTH;
    int rect_text_height = 80;

    if (!open_sans)
    {
        log_error_with_added_text("Could not initialize font: ", SDL_GetError());
    }

    SDL_Color color = get_sdl_rgba(green);

    SDL_Rect message_rect;
    message_rect.x = x_coordinate;
    message_rect.y = y_coordinate;
    message_rect.w = rect_text_width;
    message_rect.h = rect_text_height;

    SDL_Surface *surface_message = TTF_RenderText_Solid(open_sans, ulam_output, color);

    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_RenderFillRect(renderer, &message_rect);

    SDL_RenderCopy(renderer, message, NULL, &message_rect);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message);

    TTF_CloseFont(open_sans);
}

static void render_ulam_spiral(void)
{
    coordinate_t center = find_center(ROW, COLUMN);
    create_ulam_spiral(center, ulam_spiral);
    int y_position = 0;
    char possible_characters_in_a_row[80] = {'\0'}; // adding 0 will prevent C from creating random data in the string
    char possible_prime_number[MAX_NUM_OF_DIGITS + 1];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (ulam_spiral[i][j] != '*')
            {
                // no need to create add space at the last possible_prime_number
                if (j == COLUMN - 1)
                {
                    sprintf(possible_prime_number, "%d", ulam_spiral[i][j]);
                }
                else
                {
                    sprintf(possible_prime_number, "%d ", ulam_spiral[i][j]);
                }
            }
            else
            {
                // no need to create add space at the last possible_prime_number
                if (j == COLUMN - 1)
                {
                    sprintf(possible_prime_number, "%c", ulam_spiral[i][j]);
                }
                else
                {
                    sprintf(possible_prime_number, "%c ", ulam_spiral[i][j]);
                }
            }

            strcat(possible_characters_in_a_row, possible_prime_number);
            // empty out possible_prime_number
            memset(possible_prime_number, 0, strlen(possible_prime_number));
        }
        display_ulam_spiral(renderer, 0, y_position, possible_characters_in_a_row);
        y_position += 100;
        // empty out possible_characters_in_a_row
        memset(possible_characters_in_a_row, 0, strlen(possible_characters_in_a_row));
    }
}

static void render_background(void)
{
    SDL_Color background_rgba = get_sdl_rgba(black);
    SDL_SetRenderDrawColor(renderer, background_rgba.r, background_rgba.g, background_rgba.b, background_rgba.a);
}

static void render(void)
{
    // color should look like the vs code monokai background color
    render_background();
    SDL_RenderClear(renderer);
    render_ulam_spiral();
    SDL_RenderPresent(renderer);
}

static void run_program(void)
{
    while (true)
    {
        process_input();
        render();
    }
}

/**
 *  --- Public Functions ---
 **/
void run_sdl_ulam_spiral(void)
{
    run_program();
}