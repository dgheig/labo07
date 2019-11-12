/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : labo07_schaufelberger_yannick_gallay_david.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 11.11.2019

But         :
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/
#include "labo_07_schaufelberger_yannick_gallay_david.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

#define CLEAR_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

int MIN_YEAR = 1900;
int MAX_YEAR = 2300;

enum MONTHS {
   JANVIER = 1,
   FEVRIER,
   MARS,
   AVRIL,
   MAI,
   JUIN,
   JUILLET,
   AOUT,
   SEPTEMBRE,
   OCTOBRE,
   NOVEMBRE,
   DECEMBRE
};

const char DATE_SEPARATOR = '-';
const char RESTART_CHAR   = 'O';
const char STOP_CHAR      = 'N';

bool ignore_date_separator() {
   if (cin.fail())
      cin.clear();
   return getchar() != DATE_SEPARATOR;
}

bool is_bissextile(const int& year) {

   if (year % 4) return false;
   if (year % 100) return true;
   if (year % 400) return false;
   return true;
}

bool is_date_valide(const int& day, const int& month, const int& year) {
   cout << day << " " << month << " " << year << endl;

   if (year < MIN_YEAR || year > MAX_YEAR) {
      cerr << "Les dates doivent être comprises entre " << MIN_YEAR
              << " et " << MAX_YEAR
              << endl;
      return false;
   }

   if (month < JANVIER || month > DECEMBRE) {
      cerr << setfill('0')
              << "Les mois doivent être compris entre " << JANVIER
              << " et " << DECEMBRE
              << endl;
      return false;
   }

   if (day < 1 || day > 31) {
      cerr << "Les jours doivent etre positifs et inferieur ou egal a 31" << endl;
      return false;
   }
   switch (month) {

      case FEVRIER:
         if (day > 29 || (!is_bissextile(year) && day > 28)) {
            cerr << "Le nombre de jour maximum du mois de fevrier est de 29 les annee bissextile, sinon 28" << endl;
            return false;
         }

      case AVRIL:
      case JUIN:
      case SEPTEMBRE:
      case NOVEMBRE:
         if (day > 30) {
            cerr << "Le nombre de jours depassent le maximum du mois" << endl;
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
bool ask_date(const string date, int& day, int& month, int& year) {
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
void ask_for_valide_date(const string date, int& day, int& month, int& year) {
   bool re_ask = false;
   do {
      re_ask = !ask_date(date, day, month, year);
   } while (re_ask || !is_date_valide(day, month, year));
}

/**
    Check if start date is before end date
 * useless
 */
bool check_date_order(
        const int& start_day, const int& start_month, const int& start_year,
        const int& end_day, const int& end_month, const int& end_year) {

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


void ask_and_compute_delta_day_between_two_dates() {

   int start_day;
   int start_month;
   int start_year;

   int end_day;
   int end_month;
   int end_year;

   do {
      ask_for_valide_date("date de debut", start_day, start_month, start_year);
      ask_for_valide_date("date de fin", end_day, end_month, end_year);

   } while (!check_date_order(start_day, start_month, start_year,
           end_day, end_month, end_year));

   int affichage = daysBetweenDates(start_day, start_month, start_year, end_day, end_month, end_year);

   cout << affichage << endl;

}

bool ask_for_restart() {
   while(true) {
      cout << "Voulez-vous recommencer? [O/N]" << endl;
      char c = getchar();
      CLEAR_BUFFER;
      if ( c == RESTART_CHAR) return true;
      else if ( c == STOP_CHAR) return false;
   }
}

int main() {
   do {
      ask_and_compute_delta_day_between_two_dates();
   } while(ask_for_restart())
   return EXIT_SUCCESS;
}

int daysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {

   int startJulien = getDaysSinceReferenceDay(startDay, startMonth, startYear);
   cout << endl;
   int endJulien = getDaysSinceReferenceDay(endDay, endMonth, endYear);

   cout << startJulien << " : " << endJulien << endl;

   int daysBetweenDates = endJulien - startJulien;

   return daysBetweenDates;

}

int getDaysSinceReferenceDay(int day, int month, int year) {

   int a = (14 - month) / 12;
   int y = year - 1900 - a;
   int m = month + 12 * a - 3;

   int JDN = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 + 58;

   cout << "a : " << a << endl;
   cout << "y : " << y << endl;
   cout << "m : " << m << endl;
   cout << "day : " << day << endl;
   cout << "month : " << month << endl;
   cout << "year : " << year << endl;
   cout << "JDN : " << JDN << endl;

   return JDN;

}