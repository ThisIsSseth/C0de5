// get a miladi date and turn it into shamsi

#include <IOSTREAM>
using namespace std;

int main()
{
    cout << "START";

    // while (1)
    // {
    //     unsigned short int day, month, year;
    //     cout << " Enter day, month, year: \n";
    //     cin >> day >> month >> year;
    //     int days = day;
    //     // this variable holds the total count of days
    //     days += 30 * (month - 1);
    //     days += (month) / 2;
    //     if (month > 2 && year % 4 == 0)
    //         days--;

    //     else if (month > 2 && year % 4 != 0)
    //         days -= 2;

    //     if (month == 9)
    //         days++;
    //     if (month == 11)
    //         days++;
    //         // by this point we have the count of days
    //     int tday, tmonth, tyear;
    //     // the day, month & year of shamsi
    //     if (month < 3 || (month == 3 && day < 21))
    //     {
    //         tyear = year + 622;
    //     }
    //     else
    //     {
    //         tyear = year + 621;
    //     }

    //     cout << days << endl;
    // }
    // I'm not really sure about this one so let us for now do another one.

    while (1)
    {
        unsigned short int day, month, year;
        cout << " Enter day, month, year: \n";
        cin >> day >> month >> year;
        // days = total days from the مبدا تقویم میلادی
        int days = 365 * (year - 1) + (year - 1) / 4;
        if (month > 1)
            days += 31;
        if (month > 2)
            if (year % 4 == 0)
                days += 29;
            else
                days += 28;
        if (month > 3)
            days += 31;
        if (month > 4)
            days += 30;
        if (month > 5)
            days += 31;
        if (month > 6)
            days += 30;
        if (month > 7)
            days += 31;
        if (month > 8)
            days += 31;
        if (month > 9)
            days += 30;
        if (month > 10)
            days += 31;
        if (month > 11)
            days += 30;

        days += day;

        // now we start evaluating the solar days...
        int s_year, s_month, s_day;
        days -= 226899;
        // this number is the difference of the start of the miladi and shamsi
        days -= days / (365 * 4 + 1);
        s_year = days / 365;
        days = days % 365;
        cout << days;
        // below : days / 31 (we assume all months are 31 day and evaluate the num of months)
        //the we add one more to month if the number of true remaining days is more than 30 if we're in the second 6 months of the year
        s_month = days / 31 + ((days / 31 / 6) /*if we had more than 6 months*/ * ((days % 31 /* the remaining days*/ + /*the diff of days made by assuming 31day months*/ ((days / 31) % 6)) / 30));
        cout << s_month;
    }

    return 0;
}

/*months:
31   d
28/ 29   31
31    59    60

30      89  90
31      120     121
30      150     151

31      181     182
31      212     213
30

31
30
31

*/
