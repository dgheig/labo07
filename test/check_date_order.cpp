/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_07
Fichier     : labo_07_schaufelberger_yannick_gallay_david.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 11.11.2019

But         :
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

#define IGNORE_DATE_SEPARATOR cin.clear(); getchar()
#define CLEAR_BUFFER std::cin.ignore\
                     (numeric_limits<streamsize>::max(), '\n')
#define PAUSE CLEAR_BUFFER

bool is_date_valide(const int& day, const int& month, const int& year) {
    cout << day << " " << month << " " << year << endl;
    return true;
}

void ask_for_valide_date(const string date, int& day, int& month, int& year) {

    do {
        cout << "Entrez la " << date << " dans le format DD-MM-YYYY: " << endl;
        cin >> day;
        IGNORE_DATE_SEPARATOR;
        cin >> month;
        IGNORE_DATE_SEPARATOR;
        cin >> year;
        CLEAR_BUFFER;
    } while(!is_date_valide(day, month, year));
}

bool check_date_order(
    const int& start_day, const int& start_month, const int& start_year,
    const int& end_day, const int& end_month, const int& end_year) {

    if(end_year < start_year) return true;
    else if (end_year > start_year) return false;

    if(end_month < start_month) return true;
    else if (end_month > start_month) return false;

    if(end_day < start_day) return true;
    else if (end_day > start_day) return false;

    return true;
}

int main() {

    int start_day,
        start_month,
        start_year;

    int end_day,
        end_month,
        end_year;

    do {
        ask_for_valide_date(
            "date de debut",
            start_day, start_month, start_year);
        ask_for_valide_date(
            "date de fin",
            end_day, end_month, end_year);

    } while(!check_date_order(start_day, start_month, start_year,
                    end_day, end_month, end_year));



    return EXIT_SUCCESS;
}
