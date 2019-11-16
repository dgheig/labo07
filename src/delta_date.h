#ifndef DELTA_DATE_H
#define DELTA_DATE_H

#include <string>



/**
 * @return false if the buffer contains the char DATE_SEPARATOR, true if it doesn't
 * @brief This function clears the next character in the buffer,
 * and returns true if it isn't DATE_SEPARATOR
 */
bool ignore_date_separator();

/**
 * @param date string telling the user if it's the start date or end date
 * @param day input of the user
 * @param month input of the user
 * @param year input of the user
 * @return true if the date has been retrieve successfully according to DD-MM-YYYY format, else false
 * @brief This function modifies the three referenced arguments to values inputted by the user
 */
bool ask_date(const std::string& date, int& day, int& month, int& year);

/**
 * @param date
 * @param day input of the user in function ask_date()
 * @param month input of the user in function ask_date()
 * @param year input of the user in function ask_date()
 * @brief This function asks for a valid date with the format DD-MM-YYYY using ask_date function.
 * As long as the date is invalid, or the format is wrong, it asks for a new date
 */
void ask_for_valid_date(const std::string& date, int& day, int& month, int& year);

/**
 * @brief This function asks for a valid dates within a given range of dates in format DD-MM-YYYY
 *        and display the number of day between the choosen dates.
 */
void ask_and_compute_delta_day_between_two_dates();

#endif // DELTA_DATE_H

