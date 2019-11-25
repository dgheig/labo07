/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : is_date_valid.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 14.11.2019

But         : test the is_date_valid function
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include "../src/utilities.h"
#include <iostream>
using namespace std;

int exit_value = EXIT_SUCCESS;


void check_function_is_date_valid(int day, int month, int year, bool expected) {

    if (is_date_valid(day, month, year) != expected) {
        cerr << "Test does not correspond the expected result." << endl
             << "Given date:"                                   << endl
             << "Day: "                   << day                << endl
             << "Month: "                 << month              << endl
             << "Year: "                  << year               << endl
             << "Expected: " << boolalpha << expected           << endl
             << endl;
        int exit_value = EXIT_FAILURE;
    }
}

int main() {

    check_function_is_date_valid(1, 1, 2019, true);
    check_function_is_date_valid(1, 0, 2019, false);
    check_function_is_date_valid(1, 13, 2019, false);
    check_function_is_date_valid(29, 2, 2000, true);
    check_function_is_date_valid(29, 2, 2001, false);
    check_function_is_date_valid(29, 2, 1899, false);
    check_function_is_date_valid(29, 2, 2301, false);

    return exit_value;
}
