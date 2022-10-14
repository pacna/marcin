#include "global.h"

void main(int argc, char *argv[])
{
   if (is_sdl_mode(argv[1]) && init_sdl_ulam_spiral())
   {
      log_success("Starting Ulam Spiral in SDL mode");
      run_sdl_ulam_spiral();
   }
   else if (is_terminal_mode(argv[1]))
   {
      log_success("Starting Ulam Spiral in Terminal mode");
      run_terminal_ulam_spiral(ulam_spiral);
   }
   else
   {
      log_error("Unable to run app");
   }
}