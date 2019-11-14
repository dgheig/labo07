//labo_07_schaufelberger_yannick_gallay_david.h

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include <limits>

#define CLEAR_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n')

/**
 * @return false if the buffer contains the char DATE_SEPARATOR, true if it doesn't
 * @brief This function clears the next character in the buffer,
 * and returns true if it isn't DATE_SEPARATOR
 */
bool ignore_date_separator();

/**
 * @param year any given year
 * @return true if year is a leap year, false if it isn't
 */
bool is_leap_year(int year);

/**
 * @param day any number
 * @param month any number
 * @param year any number
 * @return true if the date composed of day, month and year is a valid date
 * @brief This function checks that year is between 1900 and 2300,
 * that month is between 1 and 12
 * and that day is between 1 and 28/29/30/31, depending on the month
 */
bool is_date_valid(int day, int month, int year);

/**
 * @param date string telling the user if it's the start date or end date
 * @param day 
 * @param month
 * @param year
 * @return true if the input format corresponds to DD-MM-YYYY
 */
bool ask_date(const std::string& date, int& day, int& month, int& year);

void ask_for_valid_date(const std::string& date, int& day, int& month, int& year);

bool check_date_order(
        int start_day, int start_month, int start_year,
        int end_day, int end_month, int end_year);

int days_between_dates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int get_days_since_reference_day(int day, int month, int year);


#endif // UTILITIES_H

