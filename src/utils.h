#ifndef UTILS__
#define UTILS__

typedef struct Coordinate
{
    unsigned int x;
    unsigned int y;
} coordinate_t;

extern void print_result(unsigned char input);
extern void print_ulam_spiral_in_terminal(unsigned char ulam_spiral[ROW][COLUMN]);
extern bool is_prime(int num);
extern unsigned char get_prime_number_or_not(int num);
extern bool is_even(unsigned int num);
extern coordinate_t find_center(unsigned int row, unsigned int column);
#endif