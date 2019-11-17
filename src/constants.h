#ifndef CONSTANTS_H
#define CONSTANTS_H

enum Months {
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

const int MIN_DAY  = 1;
const int MIN_MONTH = JANUAR;
const int MIN_YEAR = 1900;
const int MAX_DAY  = 31;
const int MAX_MONTH = DECEMBER;
const int MAX_YEAR = 2300;

const char DATE_SEPARATOR = '-';

#endif // CONSTANTS_H