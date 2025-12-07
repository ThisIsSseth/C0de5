#include <iostream>
using namespace std;

int main()
{
    unsigned int age;

    cin >> age;
    if (age <= 6)
    {
        cout << "Is baby. not educated.";
    }
    else if (7 <= age && age <= 12)
    {
        cout << "Elementary.";
    }
    else if (13 <= age && age <= 15)
    {
        cout << "Middle shool.";
    }
    else if (16 <= age && age <= 18)
    {
        cout << "Highschool.";
    }
    else if (19 <= age && age <= 30)
    {
        cout << "Uni.";
    }
    else
    {
        cout << "Educated.";
    }
    return 0;
}