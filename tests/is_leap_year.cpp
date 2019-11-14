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

bool check_function_is_leap_year(int year, bool expected) {

    if (is_leap_year(year) != expected) {
        cerr << "Test failed"                         << endl
             << "Year: "                  << year     << endl
             << "Expected as leap year: " << expected << endl
             << endl;
    }
}

int main() {

    check_function_is_leap_year(2000, true);

    return EXIT_SUCCESS;
}
