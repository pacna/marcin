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
   unsigned char init_num = 1;

   coordinate center = find_center(ROW, COLUMN);
   place_numbers_in_spiral(center, ulam_spiral);

   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COLUMN; j++) {
         // if (is_prime(init_num)) {
         //    ulam_spiral[i][j] = init_num;
         // } else {
         //    ulam_spiral[i][j] = '*';
         // }
         // init_num++;
         // print_result(ulam_spiral[i][j]);
         printf("%d", ulam_spiral[i][j]);
      }
      printf("\n");
   }

   // printf("%d %d \n", center.x, center.y);

   return 0;
}