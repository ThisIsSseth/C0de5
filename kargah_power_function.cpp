#include <IOSTREAM>
using namespace std;

int power (int base, int power);

int main()
{
    int a = 1, b;
    while (a != 0){
    cout << "base then power \n";
    cin >> a >> b;
    cout << power(a, b) << endl;
    }

    return 0;
}

int power (int base, int power)
{
    int res =1;
    for (int i = 0; i < power; i++)
    {
        res *= base;
    }
    return res;
}