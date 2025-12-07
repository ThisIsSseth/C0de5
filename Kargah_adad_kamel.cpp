#include <iostream>
using namespace std;

int sumofnume(int a);
bool eqchk(int adad, int sum);

int main()
{
    while (1) {
    int entry;
    cin >> entry;
    cout << sumofnume (entry) << endl;
    cout << eqchk(entry , sumofnume (entry)) << endl;
    if (eqchk(entry, sumofnume(entry)))
        cout << "Kamel"<< endl;
    else
        cout << "not kamel"<< endl; }

    return 0;
}

int sumofnume(int a)
{
    int sum = 0;

    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
            sum += i;
        else
        {
        }
    }
    return sum;
}

bool eqchk(int adad, int sum)
{

    return (adad == sum);
}