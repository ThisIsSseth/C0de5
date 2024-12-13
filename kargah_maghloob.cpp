#include <IOSTREAM>
using namespace std;

int magh(int adad);

int main()
{
    while (1)
    {
        int voorudi;
        cin >> voorudi;
        cout << magh(voorudi);
    }
    return 0;
}

int magh(int adad)
{
    int, rem, magh = 0;
    for (adad; adad != 0; adad = adad / 10)
    {
        rem = adad % 10;
        magh = magh * 10 + rem;
    }
    return magh;
}