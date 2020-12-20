#ifndef _SPIRAL
#define _SPIRAL

enum DIRECTION {
    Right = 0,
    Up = 1,
    Left = 2,
    Down = 3 
};

extern void place_numbers_in_spiral(coordinate center, unsigned char spiral[ROW][COLUMN]);
#endif