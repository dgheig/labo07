//labo_07_schaufelberger_yannick_gallay_david.h

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using namespace std;

const int MIN_YEAR = 1900;
const int MAX_YEAR = 2300;

enum MONTHS {
   JANUAR = 1,
   FEBRUAR,
   MARCH,
   APRIL,
   MAY,
   JUNE,
   JULY,
   AUGUST,
   SEPTEMBER,
   OCTOBER,
   NOVEMBER,
   DECEMBER
};

const char DATE_SEPARATOR = '-';
const char RESTART_CHAR   = 'O';
const char STOP_CHAR      = 'N';


bool is_leap_year(const int& year);

bool is_date_valide(const int& day, const int& month, const int& year);

bool ask_date(const string date, int& day, int& month, int& year);

void ask_for_valide_date(const string date, int& day, int& month, int& year);

bool check_date_order(
        const int& start_day, const int& start_month, const int& start_year,
        const int& end_day, const int& end_month, const int& end_year);

void ask_and_compute_delta_day_between_two_dates();

bool ask_for_restart();

int days_between_dates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int get_days_since_reference_day(int day, int month, int year);


#endif // UTILITIES_H

