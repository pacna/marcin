#include "global.h"

/** https://en.wikipedia.org/wiki/Primality_test **/
bool is_prime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

   int init_num = 5;

    while ((init_num * init_num) <=  num) {
        if (num % init_num == 0  || num % (init_num + 2 ) == 0) {
            return false;
        }

        init_num+=6;
    }

    return true;
}

bool is_even(unsigned int num) {
    return (num % 2) == 0;
}

unsigned char get_prime_number_or_not(int num) {
    if (is_prime(num)) {
        return num;
    } else {
        return '*';
    }
}

void print_result(unsigned char input) {
   if (input != '*') {
      printf("%d \t", input);
   } else {
      printf("%c \t", input);
   }
}

void print_ulam_spiral_in_terminal(unsigned char ulam_spiral[ROW][COLUMN]) {
   for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            print_result(ulam_spiral[i][j]);
        }
        printf("\n"); 
   }
}

coordinate find_center(unsigned int row, unsigned int column) {
    double center_row = floor(row /2 );
    double center_column;
    if (is_even(row)) {
        center_column = floor(column /2 ) - 1;
    } else {
        center_column = floor(column / 2);
    }

    coordinate center;
    center.x = (int)center_row;
    center.y = (int)center_column; 
    
    return center;
}