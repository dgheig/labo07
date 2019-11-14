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


bool ignore_date_separator() {
   if (cin.fail())
      cin.clear();
   return getchar() != DATE_SEPARATOR;
}

bool is_leap_year(int year) {

   if (year % 4) return false;
   if (year % 100) return true;
   if (year % 400) return false;
   return true;
}

bool is_date_valid(int day, int month, int year) {

   if (year < MIN_YEAR || year > MAX_YEAR) {
      cerr << "Les dates doivent etre comprises entre " << MIN_YEAR
              << " et " << MAX_YEAR
              << endl;
      return false;
   }

   if (month < JANUAR || month > DECEMBER) {
      cerr << setfill('0')
              << "Les mois doivent etre compris entre " << JANUAR
              << " et " << DECEMBER
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
         return true;

   }
   return true;
}

/**
    Return True if the input format is valide according to DD-MM-YYYY
    Else return false
*/
bool ask_date(const string& date, int& day, int& month, int& year) {
   cout << "Entrez la " << date << " dans le format DD-MM-YYYY: " << endl;
   cin >> day;
   if (ignore_date_separator()) {
      cerr << "La separation de la date doit etre '-' " << endl;
      CLEAR_BUFFER;
      return false;
   }
   cin >> month;
   if (ignore_date_separator()) {
      cerr << "La separation de la date doit etre '-' " << endl;
      CLEAR_BUFFER;
      return false;
   }
   cin >> year;
   CLEAR_BUFFER;
   if (cin.fail()) {
      cin.clear();
      return false;
   }
   return true;
}

/**
    Ask the user for date up that the date is valide
    return void
*/
void ask_for_valid_date(const string& date, int& day, int& month, int& year) {
   bool re_ask = false;
   do {
      re_ask = !ask_date(date, day, month, year);
   } while (re_ask || !is_date_valid(day, month, year));
}

/**
    Check if start date is before end date
*/
bool check_date_order(
        int start_day, int start_month, int start_year,
        int end_day, int end_month, int end_year) {

   if (end_year > start_year) return true;
   else if (end_year < start_year) {
      cerr << "L'annee de debut doit etre plus petite que l'annee de fin" << endl;
      return false;
   }

   if (end_month > start_month) return true;
   else if (end_month < start_month) {
      cerr << "Le mois de debut doit etre plus petite que le mois de fin" << endl;
      return false;
   }

   if (end_day > start_day) return true;
   else if (end_day < start_day) {
      cerr << "Le jour de debut doit etre plus petite que le jour de fin" << endl;
      return false;
   }

   return true;
}

int days_between_dates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {

   int daysSinceStart = get_days_since_reference_day(startDay, startMonth, startYear);
   cout << endl;
   int daysSinceEnd = get_days_since_reference_day(endDay, endMonth, endYear);

   int daysBetweenDates = daysSinceEnd - daysSinceStart;

   return daysBetweenDates;

}

int get_days_since_reference_day(int day, int month, int year) {

   int a = (14 - month) / 12;
   int y = year - 1900 - a;
   int m = month + 12 * a - 3;

   int days = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 + 58;

   return days;

}