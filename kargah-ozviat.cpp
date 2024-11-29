#include <iostream>
using namespace std;
// this program gets age and ozviat and sees if we are ozv and vaajed shart senni

int main()
{
    cout << "Enter age : \n";
    int age;
    cin >> age;

    bool ozviat, gift_card;
    cout << "Do you have کارت عضویت? Enter 1 for yes or 0 for no. \n";
    cin >> ozviat;
    cout << "Do you have gift card? Enter 1 for yes or 0 for no. \n";
    cin >> gift_card;
    // if bool is 1 it's true and if it's 0 it's false
    if (age >= 18 && (ozviat || gift_card))
    {
        cout << "You may Enter.\n";
    }
    else
    {
        cout << "you may not enter.\n";
    }
    return 0;
}