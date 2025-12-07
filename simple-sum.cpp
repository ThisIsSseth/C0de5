#include <iostream>
using namespace std;

//this sum code...
int main()
{
    //gets an int smaller than 1 milion and sums all int from 1 to that number
    unsigned int n;
    cin >> n;
    if (n <= 1000000)
    {
        // summing 1by1 ...
        int sum = 0;
        for (unsigned int i = 0; i <= n; i++)
        {
            sum += i;
        }
        cout << sum;
    }
    return 0;
}