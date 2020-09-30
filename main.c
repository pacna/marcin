#include <stdio.h>

#define ROW 3
#define COLUMN 3

int main() {
   int ulam_spiral[ROW][COLUMN] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}
   };

   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COLUMN; j++) {
         printf("%d", ulam_spiral[i][j]);
      }
      printf("\n");
   }

   return 0;
}