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
 * @brief This function checks that year is between a range of date given by constants,
 * that month is between 1 and 12
 * and that day is between 1 and 28/29/30/31, depending on the month
 */
bool is_date_valid(int day, int month, int year);

/*!
 * @param start_day a number between 1 and 31
 * @param start_month a number between 1 and 12
 * @param start_year a number between 1900 and 2300
 * @param end_day a number between 1 and 31
 * @param end_month a number between 1 and 12
 * @param end_year a number between 1900 and 2300
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

/*!
 * @param day
 * @param month
 * @param year
 * @return the number of days between January 1st 1900 and the date defined by day, month and year
 * @brief This function is based on the Julian Day calculation found
 * on this page : http://www.cs.utsa.edu/~cs1063/projects/Spring2011/Project1/jdn-explanation.html
 */
int get_days_since_reference_day(int day, int month, int year);


#endif // UTILITIES_H

