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


bool check_function_is_date_valid(int day, int month, int year) {

    if (!is_date_valid(day, month, year)) {
        cerr << "Test failed with following values." << endl
             << "Day: "   << day                     << endl
             << "Month: " << month                   << endl
             << "Year: "  << year                    << endl
             << endl;
    }
}

int main() {

    check_function_days_between_dates(1, 1, 2019);

    return EXIT_SUCCESS;
}
