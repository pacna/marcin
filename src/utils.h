#ifndef UTILS__
#define UTILS__

typedef struct Coordinate
{
    unsigned int x;
    unsigned int y;
} coordinate_t;

extern bool is_prime(int num);
extern unsigned char get_prime_number_or_not(int num);
extern bool is_even(unsigned int num);
extern coordinate_t find_center(unsigned int row, unsigned int column);
#endif