#include <iostream>
using namespace std;

bool even(int n);

int main()
{

    int n;
    cin >> n;
    if (even(n))
        cout << "even";
    else
        cout << "odd";

    return 0;
}

bool even(int n)
{
    return (n % 2 == 0);
}