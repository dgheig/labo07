/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : labo07_schaufelberger_yannick_gallay_david.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 11.11.2019

But         : Ask the user for valid dates in DD-MM-YYYY format and display the
              number of days between the choosen dates
Remarque(s) : The code is separated in 4 librairies:
               1. utilities  : code that is usefull to handle dates
               2. constants  : constants that are specific to this program
               3. delta_date : code that regroups all previous quoted librairies
                               and declare function specifics to this program
               4. interface  : code that is usefull to handle user interface
Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include "src/delta_date.h"
#include "src/interface.h"
#include <cstdlib>

int main() {
   do {
      ask_and_compute_delta_day_between_two_dates();
   } while(ask_for_restart());
   return EXIT_SUCCESS;
}
