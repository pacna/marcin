#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define ROW 5
#define COLUMN 5

/** https://en.wikipedia.org/wiki/Primality_test **/

bool is_prime(int num) {
   if (num <= 3) {
      return num > 1;
   } else if (num % 2 == 0 || num % 3 == 0) {
      return false;
   }

   int init_num = 5;

   while ((init_num * init_num) <=  num) {
      if ( num % init_num == 0  || num % (init_num + 2 ) == 0) {
         return false;
      }

      init_num+=6;
   }

   return true;
}

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