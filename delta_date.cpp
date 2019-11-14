#include "utilities.h"
#include "constants.h"
#include <iostream>

void ask_and_compute_delta_day_between_two_dates() {

   int start_day;
   int start_month;
   int start_year;

   int end_day;
   int end_month;
   int end_year;

   do {
      ask_for_valide_date("date de debut", start_day, start_month, start_year);
      ask_for_valide_date("date de fin", end_day, end_month, end_year);

   } while (!check_date_order(
               start_day, start_month, start_year,
               end_day, end_month, end_year));

   int delta_days = days_between_dates(
                        start_day, start_month, start_year,
                        end_day, end_month, end_year);
    std::cout << "Il y a "
              << days_between_dates(start_day, start_month, start_year, end_day, end_month, end_year)
              << " jours entre les deux dates entrees."
              << std::endl;
}

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