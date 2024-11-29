#include <IOSTREAM>
using namespace std;

int main()
{
    unsigned int age;
    bool membership;

    cout << "Enter your age: \n";
    cin >> age;
    if (age < 12 || age >= 60)
    {
        cout << "Pay 10T.";
    }
    else 
    cout << "Type 1 if you have a membership, 0 if you don't:";
    cin >> membership;

    if (age < 18 && age >= 12 && membership)
    {
        cout << "Pay 12T.";
    }
    else if (age < 18 && age >= 12 && !membership)
    {
        cout << "Pay 15T.";
    }
    else if (age < 60 && age >= 18 && membership)
    {
        cout << "Pay 20T.";
    }
    else
    {
        cout << "Pay 25T.";
    }

    return 0;
}