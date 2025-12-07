// we are gonna print sth like this:
/*
1  2   3   4   5   6   7   8   9   10
   4   6   8   10  12  14  16  18  20
       9   14 ...
*/

#include <IOSTREAM>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    while (1)
    {
        cout << endl <<"enter a number: \n";
        cin >> n;
        if (n == 0)
            break;

        // column , line of our table
        for (int l = 1; l <= n; l++)
        {
            cout << endl << setw((l - 1) * 3);
            int c = 1;
            for (; c <= n; c++)
            {
                if (c < l)
                {
                    // cout << " ";
                }
                else
                {
                    cout << l * c;
                    if (l * c < 10)
                    {
                        cout << "  ";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
    }

    return 0;
}

/*
خروجی نامرتب:
1  2  3  4  5  6  7  8  9  10
  4  6  8  10 12 14 16 18 20
     9  12 15 18 21 24 27 30
       16 20 24 28 32 36 40 
          25 30 35 40 45 50
             36 42 48 54 60
                49 56 63 70
                   64 72 80 
                      81 90
                        100
*/