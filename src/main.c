#include "main.h"

int main() {
   if(!init_program()) {
      return -1;
   }

   run_program();

   // coordinate center = find_center(ROW, COLUMN);
   // place_numbers_in_spiral(center, ulam_spiral);

   // print_ulam_spiral_in_terminal(ulam_spiral);

   return 0;
}