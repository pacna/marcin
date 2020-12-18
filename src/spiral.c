#include "global.h"

unsigned int size_of_spiral = ROW * COLUMN;

unsigned int should_go_right = true;
unsigned int should_go_up = false;

unsigned int should_go_left = true;
unsigned int should_go_down = false;

int has_more_than_max_step(unsigned int current_step, unsigned int max_step) {
    // printf("%d %d \n", current_step, max_step);

    if (current_step > max_step) {
        return 1;
    }
    return 0;
}

int is_first_step(unsigned current_step) {
    if (current_step == 0 || current_step == 1) {
        return 1;
    }
    return 0;
}
// void update_command(unsigned int cmd, unsigned int *current_step, unsigned int *max_step) {
//     if (cmd == Right) {
//         if (*current_step == *max_step) {
//             command = cmd;
//             *current_step = 1;
//         } else {
//             (*current_step)++;        
//         }
//     }
//     else if (cmd == Up) {
//         if (*current_step == *max_step) {
//             command = cmd;
//             *current_step = 1;
//         } else {
//             (*current_step)++;
//         }
//     }
//     else if (cmd == Left) {
//         if (*current_step == *max_step) {
//             command = cmd;
//             *current_step = 1;
//         } else {
//             (*current_step)++;
//         }
//     }
//     else if (cmd == Down) {
//         if (*current_step == *max_step) {
//             command = cmd;
//             *current_step = 1;
//         } else {
//             (*current_step)++;
//         }
//     }
//     else {
//         printf("Invalid command %d \n", cmd);
//     }

//     printf("%d \t \n", command);
// }

unsigned int determine_which_direction(unsigned int current_number, unsigned int *current_step, unsigned int *max_step) {
    if (current_number == 2) {
        should_go_right = false;
        should_go_up = true;
        return Right;
    }
    else if (!is_even(*max_step)) {
        (*current_step)++;
        if (*current_step == *max_step) {
            *current_step = 0;
            if (should_go_right) {
                should_go_right = false;
                should_go_up = true;
                return Right;
            }

            if (should_go_up) {
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
        if (*current_step == *max_step) {
            *current_step = 0;
            if (should_go_left) {
                should_go_left = false;
                should_go_down = true;
                return Left;
            }

            if (should_go_down) {
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

void update_step(unsigned int *current_step, unsigned int *max_step) {
    if (is_first_step(*current_step)) {
        (*max_step)++;
    }
}

void place_number(coordinate current_position, unsigned char spiral[ROW][COLUMN], int current_number) {
    unsigned int current_size = current_position.x * current_position.y;
    // make sure we aren't placing numbers outside of the spiral.
    if (current_size <= size_of_spiral ) {
        spiral[current_position.x][current_position.y] = current_number;
    }
}

void move_right(unsigned int x_position, unsigned int *y_position, unsigned char spiral[ROW][COLUMN], int current_number) {
    (*y_position)++;
    coordinate current_position;
    current_position.x = x_position;
    current_position.y = *y_position;
    place_number(current_position, spiral, current_number);

}

void move_left(unsigned int x_position, unsigned int *y_position, unsigned char spiral[ROW][COLUMN], int current_number) {
    (*y_position)--;
    coordinate current_position;
    current_position.x = x_position;
    current_position.y = *y_position;
    place_number(current_position, spiral, current_number);
}

void move_up(unsigned int *x_position, unsigned int y_position, unsigned char spiral[ROW][COLUMN], int current_number) {
    (*x_position)--;
    coordinate current_position;
    current_position.x = *x_position;
    current_position.y = y_position;
    place_number(current_position, spiral, current_number);
}

void move_down(unsigned int *x_position, unsigned int y_position, unsigned char spiral[ROW][COLUMN], int current_number) {
    (*x_position)++;
    coordinate current_position;
    current_position.x = *x_position;
    current_position.y = y_position;
    place_number(current_position, spiral, current_number);
}

void place_numbers_in_spiral(coordinate center, unsigned char spiral[ROW][COLUMN]) {
    unsigned int x_position = center.x;
    unsigned int y_position = center.y;
    unsigned int current_step = 0;
    unsigned int max_step = 0;

    spiral[center.x][center.y] = 1;

    for (int i = 2; i <= 4; i++) {
        unsigned int command = determine_which_direction(i, &current_step, &max_step);
        switch(command) {
            case Right:
                update_step(&current_step, &max_step);
                move_right(x_position, &y_position, spiral, i);
                // update_command(Up, &current_step, &max_step);
                break;

            case Up:
                move_up(&x_position, y_position, spiral, i);        
                // update_command(Left, &current_step, &max_step);
                break;

            case Left:
                update_step(&current_step, &max_step);
                move_left(x_position, &y_position, spiral, i);
                // update_command(Down, &current_step, &max_step);
                break;

            case Down:
                move_down(&x_position, y_position, spiral, i);
                // update_command(Right, &current_step, &max_step);
                break;   
        }
        // printf("%d \t %d%d \t %d \n", command, x_position, y_position, i);
    }
}