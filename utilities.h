//labo_07_schaufelberger_yannick_gallay_david.h

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using namespace std;

const int MIN_YEAR = 1900;
const int MAX_YEAR = 2300;

enum MONTHS {
   JANVIER = 1,
   FEVRIER,
   MARS,
   AVRIL,
   MAI,
   JUIN,
   JUILLET,
   AOUT,
   SEPTEMBRE,
   OCTOBRE,
   NOVEMBRE,
   DECEMBRE
};

const char DATE_SEPARATOR = '-';
const char RESTART_CHAR   = 'O';
const char STOP_CHAR      = 'N';


bool is_bissextile(const int& year);

bool is_date_valide(const int& day, const int& month, const int& year);

bool ask_date(const string date, int& day, int& month, int& year);

void ask_for_valide_date(const string date, int& day, int& month, int& year);

bool check_date_order(
        const int& start_day, const int& start_month, const int& start_year,
        const int& end_day, const int& end_month, const int& end_year);

void ask_and_compute_delta_day_between_two_dates();

bool ask_for_restart();

int daysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int getDaysSinceReferenceDay(int day, int month, int year);


#endif // UTILITIES_H

