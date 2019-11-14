//labo_07_schaufelberger_yannick_gallay_david.h

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include <limits>

#define CLEAR_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n')

bool is_leap_year(int year);

bool is_date_valide(int day, int month, int year);

bool ask_date(const std::string& date, int& day, int& month, int& year);

void ask_for_valide_date(const std::string& date, int& day, int& month, int& year);

bool check_date_order(
        int start_day, int start_month, int start_year,
        int end_day, int end_month, int end_year);



int days_between_dates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int get_days_since_reference_day(int day, int month, int year);


#endif // UTILITIES_H

