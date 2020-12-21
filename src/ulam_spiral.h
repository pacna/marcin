#ifndef _ULAM_SPIRAL
#define _ULAM_SPIRAL

enum DIRECTION {
    Right = 0,
    Up = 1,
    Left = 2,
    Down = 3 
};

extern void create_ulam_spiral(coordinate center, unsigned char spiral[ROW][COLUMN]);
#endif