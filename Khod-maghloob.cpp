#include <iostream>
using namespace std;

int main()
{
    unsigned int entry, coentry = 0, temp, entry_holder;
    cin >> entry;
    entry_holder = entry;
    if (entry < 2000000000)
    {
        while (entry != 0)
        {
            temp = entry % 10;
            coentry = coentry * 10 + temp;
            entry = entry / 10;
        }
        if (coentry == entry_holder)
            cout << "yes";
        else
            cout << "No";
    }

    return 0;
}