#include <IOSTREAM>
using namespace std;
/* خب فک کنم برای پیدا کردن ک.م.م باید اول شمارنده های یک عددو پیدا کنیم. برای
اینکارم فک کنم
باید شروع کنیم به پیدا کردن اعداد اولی که بر عدد بخش پذیرند
و بعد عددو بر اون شمارند تقسیم کنیم و بعد شمارنده رو بزاریم کنار؟
یا فک کنم بعد ازا ینکه پیداش کردیم باید اول به اونیکی
 عددم تقسیمش کنیم و اگر بخش پدیر بود اونوقت شمارنده رو به حساب بیاریم*/

/* well i guess we need a bakhsh paziri and a numerator finder
for the numerator finder, there has to be loop in amother loop so that we can find all of the same prime numerators.
we also have to check for the numerator to be prime*/

int lcm(int a1, int a2);
bool IsPrime(int num);

int main()
{ int c;
    cout << "0. lcm\n1. prime";
    cin >> c ;
    if (c == 0)
{
    int a, b;
    cin >> a >> b;
    int lcm1 = lcm(a, b);
    cout << endl<< lcm1 << endl;
}
else 
{
    cin >> c;
    if (IsPrime(c))
    cout << "yes";
    else
    cout << "no";

}
    return 0;
}

int lcm(int a1, int a2)
{
    int lcm = 1, i = 2;

    for (i; i <= a1; i++)
    {
        if (IsPrime(i))
        /* it should check that if i is prime and that if it is then allow it do things to a1 and a2 */
        {
            cout << "i is:" << i;
            while (a1 % i == 0 && a2 % i == 0)
            {
                lcm *= i;
                a1 /= i;
                a2 /= i;
            }
        }
        else
        {
            cout << "i isnt:" << i << endl;
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
        d += 2;
        IsPrime = 0;
    }

    return IsPrime;
}