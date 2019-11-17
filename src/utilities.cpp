/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : utilities.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 11.11.2019

But         :
Remarque(s) : Function ask_date(void) does not ensure that the values day, month and
              year are given on 2/2/4 digits respectively.
              Inputs such as "00001-0001-00020000" will be considered as "01-01-2000"
Compilateur :
-----------------------------------------------------------------------------------*/

#include "utilities.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
using namespace std;

enum DateOrderFlag {
   NO_ERROR,
   DAY_ERROR,
   MONTH_ERROR,
   YEAR_ERROR
};

DateOrderFlag _check_date_order(
        int start_day, int start_month, int start_year,
        int end_day, int end_month, int end_year);


bool check_date_in_correct_range(int day, int month, int year);

bool is_leap_year(int year) {

   if (year % 4) return false;
   if (year % 100) return true;
   if (year % 400) return false;
   return true;
}

bool check_date_in_correct_range(int day, int month, int year) {
   if(_check_date_order(MIN_DAY, MIN_MONTH, MIN_YEAR, day, month, year) != NO_ERROR) {
      cerr << "Les dates choisies doivent être après le "
           << MIN_DAY << '-' << MIN_MONTH << '-' << MIN_YEAR
           << endl;
      return false;
   }
   if(_check_date_order(day, month, year, MAX_DAY, MAX_MONTH, MAX_YEAR) != NO_ERROR) {
      cerr << "Les dates choisies doivent être avant le "
           << MAX_DAY << '-' << MAX_MONTH << '-' << MAX_YEAR
           << endl;
      return false;
   }
   return true;
}

bool is_date_valid(int day, int month, int year) {

   if(!check_date_in_correct_range(day, month, year)) return false;

   if (month < JANUAR || month > DECEMBER) {
      cerr << setfill('0')
           << "Les mois doivent etre compris entre "
           << setw(2) << JANUAR
           << " et "  << DECEMBER
           << endl;
      return false;
   }

   if (day < 1 || day > 31) {
      cerr << "Les jours doivent etre positifs et inferieur ou egal a 31" << endl;
      return false;
   }
   switch (month) {

      case FEBRUAR:
         if (day > 29 || (!is_leap_year(year) && day > 28)) {
            cerr << "Le nombre de jour maximum du mois de fevrier est de 29 les annee bissextile, sinon 28" << endl;
            return false;
         }

      case APRIL:
      case JUNE:
      case SEPTEMBER:
      case NOVEMBER:
         if (day > 30) {
            cerr << "Le nombre de jours depasse le maximum du mois" << endl;
            return false;
         }
   }
   return true;
}

DateOrderFlag _check_date_order(
        int start_day, int start_month, int start_year,
        int end_day, int end_month, int end_year) {

   if (end_year > start_year) return NO_ERROR;
   else if (end_year < start_year) return YEAR_ERROR;

   if (end_month > start_month) return NO_ERROR;
   else if (end_month < start_month) return MONTH_ERROR;

   if (end_day > start_day) return NO_ERROR;
   else if (end_day < start_day) return DAY_ERROR;

   return NO_ERROR;
}

bool check_date_order(
        int start_day, int start_month, int start_year,
        int end_day, int end_month, int end_year) {

   switch (_check_date_order(start_day, start_month, start_year, end_day, end_month, end_year)) {
      case NO_ERROR: return true;

      case YEAR_ERROR:
         cerr << "L'annee de debut doit etre plus petite que l'annee de fin" << endl;
         return false;
      case MONTH_ERROR:
         cerr << "Le mois de debut doit etre plus petite que le mois de fin" << endl;
         return false;
      case DAY_ERROR:
         cerr << "Le jour de debut doit etre plus petite que le jour de fin" << endl;
         return false;
   }
}

int days_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year) {

   int days_since_start = get_days_since_reference_day(start_day, start_month, start_year);
   int days_since_end = get_days_since_reference_day(end_day, end_month, end_year);

   return days_since_end - days_since_start;

}

int get_days_since_reference_day(int day, int month, int year) {

   const int DAY_PER_YEAR   = 365;
   const int MONTH_PER_YEAR = 12;
   const int REFERENCE_YEAR = 1900;

   int start_of_year_shifter = (14 - month) / MONTH_PER_YEAR;
   int number_of_months = month + MONTH_PER_YEAR * start_of_year_shifter - 3;
   int number_of_years = year - REFERENCE_YEAR - start_of_year_shifter;
   int number_of_leap_years = number_of_years / 4 - number_of_years / 100 + number_of_years / 400;

   int days = day + (153 * number_of_months + 2) / 5 + DAY_PER_YEAR * number_of_years + number_of_leap_years + 58;

   return days;

}