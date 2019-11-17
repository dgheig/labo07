/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : check_days_between_dates.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 14.11.2019

But         : test the days_between_dates function
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include "../src/utilities.h"
#include <iostream>
using namespace std;


void check_function_days_between_dates(
    int start_day, int start_month, int start_year,
    int end_day, int end_month, int end_year,
    int expected ) {

    int result;

    result = days_between_dates(
        start_day, start_month, start_year,
        end_day, end_month, end_year);

    if (result != expected) {
        cerr << "Test does not correspond the expected result."         << endl
             << "Given dates:"                                          << endl
             << start_day << '-' << start_month << '-' << start_year    << endl
             << end_day   << '-' << end_month   << '-' << end_year      << endl
             << "Expected: "     << expected                            << endl
             << "Test result: "  << result                              << endl
             << endl;
    }
}

int main() {

   check_function_days_between_dates(
            1, 1, 2019,
            1, 3, 2019,
            59
    );
   check_function_days_between_dates(
            1, 1, 2019,
            31, 12, 2019,
            364
    );
   check_function_days_between_dates(
            1, 1, 2016,
            31, 12, 2016,
            365
    );
   check_function_days_between_dates(
            1, 1, 1900,
            31, 12, 2000,
            36524
    );
   check_function_days_between_dates(
            1, 1, 1900,
            31, 12, 1970,
            25567
    );
   check_function_days_between_dates(
            6, 2, 1900,
            1, 3, 1908,
            2945
    );



    return EXIT_SUCCESS;
}
