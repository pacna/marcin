#include <math.h>
#include "global.h"

/** https://en.wikipedia.org/wiki/Primality_test **/
int is_prime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

   int init_num = 5;

    while ((init_num * init_num) <=  num) {
        if ( num % init_num == 0  || num % (init_num + 2 ) == 0) {
            return 0;
        }

        init_num+=6;
    }

    return 1;
}

int is_even(unsigned int num) {
    return (num % 2) == 0;
}

coordinate find_center(unsigned int row, unsigned int column) {
    double center_row;
    double center_column;
    if (is_even(row)) {
        center_row = floor(row /2 ) - 1;
        center_column = floor(column /2 ) - 1;
    } else {
        center_row = floor(row / 2 );
        center_column = floor(column / 2);
    }

    coordinate center;
    center.x = (int)center_row;
    center.y = (int)center_column; 
    
    return center;
}