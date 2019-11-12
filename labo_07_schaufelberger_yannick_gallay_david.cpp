/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : labo07_schaufelberger_yannick_gallay_david.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 11.11.2019

But         :
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/
#include "utilities.h"
#include <cstdlib>


int main() {
   do {
      ask_and_compute_delta_day_between_two_dates();
   } while(ask_for_restart());
   return EXIT_SUCCESS;
}
