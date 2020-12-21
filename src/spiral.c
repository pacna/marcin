#include "global.h"

unsigned int size_of_spiral = ROW * COLUMN;

// order matters. right -> up
unsigned int should_go_right = true;
unsigned int should_go_up = false;
// order matters. left -> down
unsigned int should_go_left = true;
unsigned int should_go_down = false;

unsigned int determine_which_direction(unsigned int *current_step, unsigned int *max_step) {
    if (!is_even(*max_step)) {
        (*current_step)++;
        // order matters. right -> up
        if (*current_step == *max_step) {
            *current_step = 0;
            if (should_go_right) {
                should_go_right = false;
                should_go_up = true;
                return Right;
            }

            if (should_go_up) {
                (*max_step)++;
                should_go_up = false;
                should_go_right = true;
                return Up;
            }
        }

        if (should_go_right) {
            return Right;
        }

        if (should_go_up) {
            return Up;
        }
    }
    else if (is_even(*max_step)) {
        (*current_step)++;
        // order matters. left -> down
        if (*current_step == *max_step) {
            *current_step = 0;
            if (should_go_left) {
                should_go_left = false;
                should_go_down = true;
                return Left;
            }

            if (should_go_down) {
                (*max_step)++;
                should_go_down = false;
                should_go_left = true;
                return Down;
            }
        }

        if (should_go_left) {
            return Left;
        }

        if (should_go_down) {
            return Down;
        }
    }
}

void place_number(coordinate current_position, unsigned char spiral[ROW][COLUMN], unsigned char prime_number) {
    unsigned int current_size = current_position.x * current_position.y;
    // make sure we aren't placing numbers outside of the spiral.
    if (current_size <= size_of_spiral) {
        spiral[current_position.x][current_position.y] = prime_number;
    }
}

void move_right(unsigned int x_position, unsigned int *y_position, unsigned char spiral[ROW][COLUMN], unsigned char prime_number) {
    (*y_position)++;
    coordinate current_position;
    current_position.x = x_position;
    current_position.y = *y_position;
    place_number(current_position, spiral, prime_number);

}

void move_left(unsigned int x_position, unsigned int *y_position, unsigned char spiral[ROW][COLUMN], unsigned char prime_number) {
    (*y_position)--;
    coordinate current_position;
    current_position.x = x_position;
    current_position.y = *y_position;
    place_number(current_position, spiral, prime_number);
}

void move_up(unsigned int *x_position, unsigned int y_position, unsigned char spiral[ROW][COLUMN], unsigned char prime_number) {
    (*x_position)--;
    coordinate current_position;
    current_position.x = *x_position;
    current_position.y = y_position;
    place_number(current_position, spiral, prime_number);
}

void move_down(unsigned int *x_position, unsigned int y_position, unsigned char spiral[ROW][COLUMN], unsigned char prime_number) {
    (*x_position)++;
    coordinate current_position;
    current_position.x = *x_position;
    current_position.y = y_position;
    place_number(current_position, spiral, prime_number);
}

void place_numbers_in_spiral(coordinate center, unsigned char spiral[ROW][COLUMN]) {
    unsigned int x_position = center.x;
    unsigned int y_position = center.y;
    unsigned int current_step = 0;
    unsigned int max_step = 1;

    spiral[center.x][center.y] = '*';

    for (int i = 2; i <= size_of_spiral; i++) {
        unsigned int command = determine_which_direction(&current_step, &max_step);
        unsigned char prime_number = get_prime_number_or_not(i);

        switch(command) {
            case Right:
                move_right(x_position, &y_position, spiral, prime_number);
                break;

            case Up:
                move_up(&x_position, y_position, spiral, prime_number);
                break;

            case Left:
                move_left(x_position, &y_position, spiral, prime_number);
                break;

            case Down:
                move_down(&x_position, y_position, spiral, prime_number);
                break;   
        }
    }
}