//labo_07_schaufelberger_yannick_gallay_david.h

#ifndef LABO07_SCHAUFELBERGER_YANNICK_GALLAY_DAVID_H
#define LABO07_SCHAUFELBERGER_YANNICK_GALLAY_DAVID_H

#include <string>
using namespace std;

bool is_bissextile(const int& year);

bool is_date_valide(const int& day, const int& month, const int& year);

bool ask_date(const string date, int& day, int& month, int& year);

void ask_for_valide_date(const string date, int& day, int& month, int& year);

bool check_date_order(
        const int& start_day, const int& start_month, const int& start_year,
        const int& end_day, const int& end_month, const int& end_year);

int daysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int getDaysSinceReferenceDay(int day, int month, int year);


#endif /* LABO07_SCHAUFELBERGER_YANNICK_GALLAY_DAVID_H */

