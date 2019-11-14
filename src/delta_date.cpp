#include "utilities.h"
#include "delta_date.h"
#include "constants.h"
#include <iostream>
#include <string>

using namespace std;

void ask_and_compute_delta_day_between_two_dates() {

   int start_day;
   int start_month;
   int start_year;

   int end_day;
   int end_month;
   int end_year;

   do {
      ask_for_valid_date("date de debut", start_day, start_month, start_year);
      ask_for_valid_date("date de fin", end_day, end_month, end_year);

   } while (!check_date_order(
               start_day, start_month, start_year,
               end_day, end_month, end_year));

    cout << "Il y a "
              << days_between_dates(start_day, start_month, start_year, end_day, end_month, end_year)
              << " jours entre les deux dates entrees."
              << endl;
}

bool ask_date(const string& date, int& day, int& month, int& year) {

   cout << "Entrez la " << date << " dans le format DD-MM-YYYY: " << endl;
   cin >> day;
   if (ignore_date_separator()) {
      cerr << "La separation de la date doit etre '-' " << endl;
      CLEAR_BUFFER;
      return false;
   }
   cin >> month;
   if (ignore_date_separator()) {
      cerr << "La separation de la date doit etre '-' " << endl;
      CLEAR_BUFFER;
      return false;
   }
   cin >> year;
   CLEAR_BUFFER;
   if (cin.fail()) {
      cin.clear();
      return false;
   }
   return true;

}

/**
    Ask the user for date up that the date is valide
    return void
*/
void ask_for_valid_date(const string& date, int& day, int& month, int& year) {

   bool re_ask = false;
   do {
      re_ask = !ask_date(date, day, month, year);
   } while (re_ask || !is_date_valid(day, month, year));

}