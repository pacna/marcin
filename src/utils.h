#ifndef UTILS
#define UTILS

typedef struct Coordinate {
    unsigned int x;
    unsigned int y;
} coordinate;

extern bool is_prime(int num);
extern bool is_even(unsigned int num);
extern coordinate find_center(unsigned int row, unsigned int column);
#endif