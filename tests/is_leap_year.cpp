/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : is_leap_year.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 14.11.2019

But         : test the is_leap_year function
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include "../src/utilities.h"
#include <iostream>
using namespace std;

int exit_value = EXIT_SUCCESS;


bool check_function_is_leap_year(int year, bool expected) {

    if (is_leap_year(year) != expected) {
        cerr << "Test failed"                                      << endl
             << "Year: "                  << year                  << endl
             << "Expected as leap year: " << boolalpha << expected << endl
             << endl;
        int exit_value = EXIT_FAILURE;
    }
}

int main() {

    check_function_is_leap_year(2000, true);
    check_function_is_leap_year(2001, false);
    check_function_is_leap_year(1900, false);

    return exit_value;
}
