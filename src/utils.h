#ifndef IS_PRIME
#define IS_PRIME

typedef struct Coordinate {
    unsigned int x;
    unsigned int y;
} coordinate;

extern int is_prime(int num);
extern int is_even(unsigned int num);
extern coordinate find_center(unsigned int row, unsigned int column);
#endif