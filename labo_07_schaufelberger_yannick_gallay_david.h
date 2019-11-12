#include <string>
using namespace std;

bool is_bissextile(const int& year);
bool is_date_valide(const int& day, const int& month, const int& year);
bool ask_date(const string date, int& day, int& month, int& year);
void ask_for_valide_date(const string date, int& day, int& month, int& year);
bool check_date_order(
    const int& start_day, const int& start_month, const int& start_year,
    const int& end_day, const int& end_month, const int& end_year);
