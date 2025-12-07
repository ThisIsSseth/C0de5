#include <IOSTREAM>
using namespace std;

int main()
{
    int day, year, month, week;
    cin >> day;
    year = day /365;
    day = day %365;
    month = day / 30;
    day = day % 30 - month;
    day = day + (month / 6 ) * ( month % 6 ) ;
    week = day / 7;
    day = day % 7;




    return 0;
}