#include "main.h"

int main(int argc, char *argv[]) {
   if (argc == TERMINAL_MODE) {      
      coordinate center = find_center(ROW, COLUMN);
      create_ulam_spiral(center, ulam_spiral);

      print_ulam_spiral_in_terminal(ulam_spiral);
   } 
   else {
      if(!init_sdl_ulam_spiral()) {
         return -1;
      }

      run_sdl_ulam_spiral();
   }

   return 0;
}