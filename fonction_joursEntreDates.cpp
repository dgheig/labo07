#include <iostream>
#include <cstdlib>
#include <limits> //numeric_limits
#include <cmath>

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

using namespace std;

int daysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int convertToJulienDays(int day, int month, int year);

int convertToJulienDaysRevised(int day, int month, int year);

int main() {

   char recommencer;
   const char RECOMMENCER_OUI = 'o';
   const char RECOMMENCER_NON = 'n';

   do {

      int startDay;
      int startMonth;
      int startYear;
      int endDay;
      int endMonth;
      int endYear;

      cout << "Veuillez entrer une date : ";
      cin >> startDay >> startMonth >> startYear;

      VIDER_BUFFER;

      cout << "Veuillez entrer une date : ";
      cin >> endDay >> endMonth >> endYear;

      VIDER_BUFFER;

      int affichage = daysBetweenDates(startDay, startMonth, startYear, endDay, endMonth, endYear);

      cout << affichage << endl;

      cout << "Voulez vous recommencer ["
              << RECOMMENCER_OUI << "|"
              << RECOMMENCER_NON << "] : ";
      cin >> recommencer;
      VIDER_BUFFER;

      while (recommencer != RECOMMENCER_OUI && recommencer != RECOMMENCER_NON) {

         cout << "Mauvaise entree, merci d'entrer "
                 << RECOMMENCER_OUI << " ou "
                 << RECOMMENCER_NON << " : ";
         cin >> recommencer;
         VIDER_BUFFER;
      }

   } while (recommencer == RECOMMENCER_OUI);

   cout << "Presser [Enter] pour quitter" << endl;
   VIDER_BUFFER;
   return EXIT_SUCCESS;
}

int daysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {

   int startJulien = convertToJulienDaysRevised(startDay, startMonth, startYear);
   cout << endl;
   int endJulien = convertToJulienDaysRevised(endDay, endMonth, endYear);

   cout << startJulien << " : " << endJulien << endl;

   int daysBetweenDates = endJulien - startJulien;

   return daysBetweenDates;

}

int convertToJulienDays(int day, int month, int year) {

   int a = (int) trunc((14 - month) / 12);
   int y = year + 4800 - a;
   int m = month + 12 * a - 3;

   int JDN = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

   cout << "a : " << a << endl;
   cout << "y : " << y << endl;
   cout << "m : " << m << endl;
   cout << "day : " << day << endl;
   cout << "month : " << month << endl;
   cout << "year : " << year << endl;
   cout << "JDN : " << JDN << endl;

   return JDN;

}

int convertToJulienDaysRevised(int day, int month, int year) {

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