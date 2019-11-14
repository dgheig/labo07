/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : check_date_order.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 14.11.2019

But         : test the check_date_order function
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include "../utilities.h"
#include <iostream>
using namespace std;


bool check_function_check_date_order(
    int start_day, int start_month, int start_year,
    int end_day, int end_month, int end_year,
    bool expected ) {

    bool result;

    result = check_date_order(
        start_day, start_month, start_year,
        end_day, end_month, end_year);

    if (result != expected) {
        cerr << "Test does not correspond the expected result."         << endl
             << "Given dates:"                                          << endl
             << start_day << '-' << start_month << '-' << start_year    << endl
             << end_day   << '-' << end_month   << '-' << end_year      << endl
             << "Expected: "    << boolalpha << expected                << endl
             << "Test result: " << boolalpha << result                  << endl
             << endl;
    }

}

int main() {

    check_function_check_date_order(
            1, 1, 2019,
            1, 3, 2019,
            true
    );

    check_function_check_date_order(
            1, 1, 2019,
            1, 3, 2000,
            false
    );



    return EXIT_SUCCESS;
}
