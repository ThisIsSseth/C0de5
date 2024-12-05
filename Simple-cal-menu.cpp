#include <IOSTREAM>
using namespace std;

int main()
{
    float res, ent;
    int function_name;
    cout << "1. +\n"
         << "2. -\n"
         << "3. *\n"
         << "4. /\n"
         << "5. show res\n";
    cin >> res >> function_name;

    while (function_name != 5)
    {
        cin >> ent;
        if (function_name == 1)
        {
            res += ent;
        }
        else if (function_name == 2)
        {
            res -= ent;
        }
        else if (function_name == 3)
        {
            res *= ent;
        }
        else if (function_name == 4)
        {
            res /= ent;
        }
        cout << res;
        cin >> function_name;
    }
    cout << "done";
    return 0;
}