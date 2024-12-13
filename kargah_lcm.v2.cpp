#include <IOSTREAM>
using namespace std;
// find lcm ک م م

/* خب فک کنم برای پیدا کردن ک.م.م باید اول شمارنده های یک عددو پیدا کنیم. برای
اینکارم فک کنم
باید شروع کنیم به پیدا کردن اعداد اولی که بر عدد بخش پذیرند
و بعد عددو بر اون شمارند تقسیم کنیم و بعد شمارنده رو بزاریم کنار؟
یا فک کنم بعد ازا ینکه پیداش کردیم باید اول به اونیکی
 عددم تقسیمش کنیم و اگر بخش پدیر بود اونوقت شمارنده رو به حساب بیاریم*/

/* well i guess we need a bakhsh paziri and a numerator finder
for the numerator finder, there has to be loop in another loop so that we can find all of the same prime numerators.
we also have to check for the numerator to be prime*/

int lcm(int a1, int a2);
//lcm calculates the ک م م of two entries by finding the common prime numerators. it calls IsPrime in itself
bool IsPrime(int num);

int main()
{ 
    int a =1, b;
    // a while to run it in as many times as we want
    while ( a != 0){
    cin >> a >> b;
    // ok i got it all mixed up. I've been calculating gcd so now to get lcm...
    int lcm1 = a*b / lcm ( a, b);
    cout << endl<< lcm1 << endl << "_____";
    }
    return 0;
}

int lcm(int a1, int a2)
{
    int lcm = 1, i = 2;

    for (i; i <= a1; i++) /*if its not i <= a1 and i < a1 instead, then it doesn't count the last remaining a1 that is a
    prime itself so it neds to be <= to calculate the last a1 too*/
    {
        if (IsPrime(i))
        /* it should check that if i is prime and that if it is then allow it do things to a1 and a2 */
        {
            while (a1 % i == 0 && a2 % i == 0)
            {
                lcm *= i;
                a1 /= i;
                a2 /= i;
            }
        }
        else
        {
        }
    }
    return lcm;
}

bool IsPrime(int num)
{

    bool IsPrime = true;
    int d = 2;
    int bazeh = num / 2;
    if (num == 2)
    {
    }
    else if (num % d != 0)
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
        IsPrime = 0;
    }

    return IsPrime;
}