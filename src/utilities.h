//labo_07_schaufelberger_yannick_gallay_david.h

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include <limits>

#define CLEAR_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n')

/*!
 * @param year any given year
 * @return true if year is a leap year, else false
 */
bool is_leap_year(int year);

/*!
 * @param day any number
 * @param month any number
 * @param year any number
 * @return true if the date composed of day, month and year is a valid date
 * @brief This function checks that the date exists and is between a given range of dates
 */
bool is_date_valid(int day, int month, int year);

/*!
 * @param start_day day of the month (1 - 31 depending on the month)
 * @param start_month a number between 1 and 12
 * @param start_year a number between MIN_YEAR and MAX_YEAR
 * @param end_day day of the month (1 - 31)
 * @param end_month a number between 1 and 12
 * @param end_year a number between MIN_YEAR and MAX_YEAR
 * @return true if the date composed of start_day, start_month and start_year is
 * before the date composed of end_day, end_month and end_year
 */
bool check_date_order(
        int start_day, int start_month, int start_year,
        int end_day, int end_month, int end_year);

/*!
 * @param startDay
 * @param startMonth
 * @param startYear
 * @param endDay
 * @param endMonth
 * @param endYear
 * @return the number of days between the start date and the end date
 * @brief This returns a negative number if the start date is after the end date
 */
int days_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year);


#endif // UTILITIES_H

