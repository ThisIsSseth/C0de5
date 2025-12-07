// this is the same as isPrime but it's as a function
#include <IOSTREAM>
using namespace std;

bool IsPrime(int num);

int main()
{
    int a =1;
    while (a != 0){
    cin >> a;
    if (IsPrime(a))
    {
        cout << "Prime";
    }
    else
        cout << "not Prime";
    }

    return 0;
}

bool IsPrime(int num)
{

    bool IsPrime = true;
    int d = 2;
    int bazeh = num / 2;
    if (num % d != 0)
    {
        d = 3;
        while ((d <= bazeh) && (IsPrime))
        {
            IsPrime = (num % d) ? 1 : 0;
            // above means if a divided by d has any remainings, it means that its not dividebles by that number
            // so the value of (a%d)will be a number and not 0 and that returns T which puts 1 in IsPrime
            // and if a is divideble by d it makes IsPrime 0 which means it's false and thus the loop will break.
            d += 2;
        }
    }
    else
    {
        d += 2;
        IsPrime = 0;
    }

    return IsPrime;
}