#include <IOSTREAM>
using namespace std;

int main()
{
    bool IsPrime = true;
    int a, d = 2;
    cin >> a;
    int bazeh = a / 2;
    if (a % d != 0)
    {
        d = 3;
        while ((d <= bazeh) && (IsPrime))
        {
            IsPrime = (a % d) ? 1 : 0;
            // above means if a divided by d has any remainings, it means that its not dividebles by that number
            //so the value of (a%d)will be a number and not 0 and that returns T which puts 1 in IsPrime
            //and if a is divideble by d it makes IsPrime 0 which means it's false and thus the loop will break.
            d += 2;
        }
    }
    else
    {
        d += 2;
        IsPrime = 0;
    }
    if (IsPrime)
    {
        cout << "Is prime.";
    }
    else
    {
        d -= 2;
        cout << "Is not prime." << d;
    }
    return 0;
}