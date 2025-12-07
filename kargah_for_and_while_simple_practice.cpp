// this code prints even numbers from 1 to 100 and the sum of them

#include <IOSTREAM>
using namespace std;

int main()
{
    int i, sum=0;
    for (i=2; i<=100; i+=2)
    {
        cout << i<< "\n";
        sum += i;
    }
    cout << sum;
    
    return 0;}
