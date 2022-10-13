#ifndef ULAM_SPIRAL__
#define ULAM_SPIRAL__

enum DIRECTION
{
    Right = 0,
    Up = 1,
    Left = 2,
    Down = 3
};

extern void create_ulam_spiral(coordinate_t center, unsigned char spiral[ROW][COLUMN]);
#endif