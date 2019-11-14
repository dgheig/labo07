#ifndef DELTA_DATE_H
#define DELTA_DATE_H

#include <string>
void ask_and_compute_delta_day_between_two_dates();

/**
 * @param date string telling the user if it's the start date or end date
 * @param day input by the user
 * @param month input by the user
 * @param year input by the user
 * @return true if the input format corresponds to DD-MM-YYYY
 * @brief This function modifies the three referenced arguments to values inputted by the user
 */
bool ask_date(const std::string& date, int& day, int& month, int& year);

/**
 * @param date
 * @param day input by the user in function ask_date()
 * @param month input by the user in function ask_date()
 * @param year input by the user in function ask_date()
 * @brief This function asks for a valid date with the format DD-MM-YYYY.
 * As long as the date is invalid, or the format is wrong, it asks for a new date
 */
void ask_for_valid_date(const std::string& date, int& day, int& month, int& year);

#endif // DELTA_DATE_H

