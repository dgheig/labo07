#include "interface.h"
#include <iostream>
#include <limits>

#define CLEAR_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n')

bool ask_for_restart() {
   while(true) {
      std::cout << "Voulez-vous recommencer? ["
                << RESTART_CHAR << "/" << STOP_CHAR
                << "]" << std::endl;
      char c = (char) getchar();
      CLEAR_BUFFER;
      if ( c == RESTART_CHAR) return true;
      else if ( c == STOP_CHAR) return false;
   }
}