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


bool check_function_days_between_dates(
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
            58
    );



    return EXIT_SUCCESS;
}
