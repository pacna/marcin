#include "global.h"

/**
 *  --- Private Functions ---
 **/
static void print_result(unsigned char input)
{
    if (input != '*')
    {
        printf("%d \t", input);
    }
    else
    {
        printf("%c \t", input);
    }
}

static void setup(void)
{
    coordinate_t center = find_center(ROW, COLUMN);
    create_ulam_spiral(center, ulam_spiral);
}

static void run(void)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            print_result(ulam_spiral[i][j]);
        }
        printf("\n");
    }
}

static void run_program(void)
{
    setup();
    run();
}
/**
 *  --- Public Functions ---
 **/
void run_terminal_ulam_spiral(unsigned char ulam_spiral[ROW][COLUMN])
{
    run_program();
}