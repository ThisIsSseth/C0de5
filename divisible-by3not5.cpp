#include <iostream>
using namespace std;
int main()
{
    unsigned int n;
    unsigned int i;
    cin >> n;
    if (n <= 1000000)
    {
        for (i = 1; i != n; i++)
        {
            if ((i % 3 == 0) && (i % 5) != 0)
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}