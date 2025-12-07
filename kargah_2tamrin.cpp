#include <IOSTREAM>
using namespace std;

int main()
{
    // gives us the max out of 5 entries
    int a, b, c, d, e, max;
    cin >> a >> b >> c >> d >> e;

    max = (a > b) ? a : b;
    max = (c > max) ? c : max;
    max = (d > max) ? d : max;
    max = (e > max) ? e : max;

    cout << max;

    // prints a chrismass tree
    cout << "*\n**\n***\n****\n*****";

    int number, j = 0;

    cin >> number;
    for (int i = 0; i < number; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}