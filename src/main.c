#include <stdio.h>
#include <ctype.h>
#include "global.h"

#define ROW 5
#define COLUMN 5


void print_result(unsigned char input) {
   if (input != '*') {
      printf("%d \t", input);
   } else {
      printf("%c \t", input);
   }
}

int main() {
   unsigned char ulam_spiral[ROW][COLUMN] = {'\0'};
   unsigned char init_num = 1;

   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COLUMN; j++) {
         if (is_prime(init_num)) {
            ulam_spiral[i][j] = init_num;
         } else {
            ulam_spiral[i][j] = '*';
         }
         init_num++;
         print_result(ulam_spiral[i][j]);
      }
      printf("\n");
   }

   return 0;
}