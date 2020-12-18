#include <ctype.h>
#include "global.h"

void print_result(unsigned char input) {
   if (input != '*') {
      printf("%d \t", input);
   } else {
      printf("%c \t", input);
   }
}

int main() {
   unsigned char ulam_spiral[ROW][COLUMN] = {'\0'};

   coordinate center = find_center(ROW, COLUMN);
   place_numbers_in_spiral(center, ulam_spiral);

   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COLUMN; j++) {
         if (!is_prime(ulam_spiral[i][j])) {
            ulam_spiral[i][j] = '*';
         }

         print_result(ulam_spiral[i][j]);
      }

      printf("\n");
      
   }

   return 0;
}