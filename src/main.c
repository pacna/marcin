#include "global.h"

void main(int argc, char *argv[])
{
   if (argc == TERMINAL_MODE)
   {
      coordinate_t center = find_center(ROW, COLUMN);
      create_ulam_spiral(center, ulam_spiral);

      print_ulam_spiral_in_terminal(ulam_spiral);
   }
   else
   {
      if (!init_sdl_ulam_spiral())
      {
         return;
      }

      run_sdl_ulam_spiral();
   }
}