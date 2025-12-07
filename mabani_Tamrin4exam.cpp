// will do: 1. convert decimal to binary 2."" dec 2 hex 3. show how 5 numbers are equal.
// 4. print a onion square  6. cins the size and data of an array and gives the poijnts
// where they are the lowest in their row and the highest in their column
/*
do num 6 (the saddle thing)
do num 7.2 this needs structures so idk
*/
#include <iostream>
#include <MATH.H>
#include <STRING>
#include <IOMANIP>
using namespace std;

void d2b(int d);                                       // 1
void d2Hex(int d);                                     // 2
string eqstat(int n1, int n2, int n3, int n4, int n5); // 3
void oSqua(int n);                                     // 4
void calculate_pi();                                   // 5
void yesterday(int, int, int);                         // 8
string counter( int);
void tamrin_structure();

int main()
{

    cout << "\n Choose from the list below what you want to do: \n (Enter the num)";
    bool flag = true;
    while (flag)
    {
        int n;
        cout << " \n1. Decimal to Binary\n"
                "2. Decimal to Hex\n"
                "3. Give 5 int, get eq stat\n"
                "4. Onion square\n"
                "5. Get pi\n"
                "6. Give size & data of matrix and find saddle point\n"
                "7. Book library\n"
                "8. Give a date and get the day before\n"
                "9. Give n number, get max, min, sum, average\n"
                "10. Pointer test\n"
                "0 <=EXIT\n ";
        // in each of the case a function is called to do what we want
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "\n Enter the decimal number in the range\n(0 to 255)\n";
            int deci;
            cin >> deci;
            d2b(deci);
            break;
        }
        case 2:
        {
            cout << "\n Enter the decimal number in the range\n(0 to 65535)\n";
            int deci;
            cin >> deci;
            d2Hex(deci);
            break;
        }
        case 3:
        {
            int a, b, c, d, e;
            cout << "Enter 5 num to know eq.stat";
            cin >> a >> b >> c >> d >> e;
            cout << "Equality state:" << eqstat(a, b, c, d, e);
            break;
        }
        case 4:
        {
            int n = 0;
            cout << "Enter an odd number:\nmax: 17\n";
            cin >> n;
            while (n % 2 == 0 || n > 17 || n <= 0)
            {
                cout << "Error:not odd or is more than 17!\n";
                cin >> n;
            }
            oSqua(n);
            break;
        }
        case 5:
        {
            calculate_pi();
            break;
        }
        case 6:
        {

            break;
        }
        case 7:
        {
            int n;
            cout << "Choose:\n1. Use default book table\n2. Enter custom table\n";
            cin >> n;
            switch (n)
            {
            case 1:

                break;
            case 2:
            {

                break;
            }

            default:
                {cout << "You chose a non-existent option.";
                break;}
            }
        }
        case 8:
        {
            int yyyy, mm, dd;
            cout << " Enter year then month then day.";
            cin >> yyyy >> mm >> dd;
            yesterday(yyyy, mm, dd);
            break;
        }
        case 9:
        {
            int entry, max, min, sum, n;
            cout << "\nHow many numbers do you want to add?\n";
            cin >> n;
            cout << "Nice!\nOk enter the first number:";
            cin >> entry;
            max = entry; min = entry;
            sum = entry;
            for ( int m = 2; m <= n  ; m++)
            {
                cout << "ok, enter " << m << counter (m) <<" number:";
                cin >> entry;
                if ( max < entry )
                    max = entry;
                    else if ( min > entry)
                    min = entry;
                sum += entry;
            }
            cout << "\nmax: " << max << "\nmin: " << min << "\nsum: " << sum << " and average: " << sum/n;
            
            break;
        }
        case 10:
        {
            tamrin_structure();
            break;
        }
        case 0:
            return 0;

        default:
            flag = 0;
            break;
        }
    }
    return 0;
}

void d2b(int d)
{
    int bi = 0, i = 1;
    if (d < 0 || d > 255)
        cout << " Out of range \n ";
    else
    {
        while (d >> 1)
        {
            bi += d % 2 * i;
            i *= 10;
            d = d >> 1;
        }
        bi += d % 2 * i;
    }
    cout << bi;
}

void d2Hex(int d)
{
    if (d < 0 || d > 65535)
        cout << " Out of range \n ";
    else
    {
        char h1 = 'h', h2 = 'h', h3 = 'h', h4 = 'h';
        cout << " 0X";
        for (int i = 0; i < 4; i++)
        {
            if (d % 16 < 10)
                h4 = '0' + d % 16;
            else
            {
                int rem = d % 16;
                switch (rem)
                {
                case 10:
                {
                    h4 = 'A';
                    break;
                }
                case 11:
                {
                    h4 = 'B';
                    break;
                }
                case 12:
                {
                    h4 = 'C';
                    break;
                }
                case 13:
                {
                    h4 = 'D';
                    break;
                }
                case 14:
                {
                    h4 = 'E';
                    break;
                }
                case 15:
                {
                    h4 = 'F';
                    break;
                }
                }
            }
            d = d >> 4;
            if (h1 == 'h')

                h1 = h4;

            else if (h2 == 'h')
                h2 = h4;
            else if (h3 == 'h')
                h3 = h4;
            else
                break;
        }
        cout << h4 << h3 << h2 << h1;
    }
}

string eqstat(int n1, int n2, int n3, int n4, int n5)
{
    string stat;
    // there're just tones of else ifs checking each codition seperately
    if (n1 == n2 && n2 == n3 && n3 == n4 && n4 == n5)
        stat = "All";
    else if ((n1 == n2 && n2 == n3 && n3 == n4) || (n5 == n2 && n2 == n3 && n3 == n4) || (n1 == n5 && n5 == n3 && n3 == n4) || (n1 == n2 && n2 == n5 && n5 == n4) || (n1 == n2 && n2 == n3 && n3 == n5))
        stat = "4 Equal";
    else if ((n1 == n2 && n2 == n3 && n4 == n5) || (n4 == n2 && n2 == n3 && n1 == n5) || (n2 == n5 && n3 == n1 && n1 == n4) || (n5 == n3 && n1 == n2 && n2 == n4) || (n5 == n2 && n2 == n3 && n4 == n1) || (n4 == n2 && n1 == n3 && n3 == n5) || (n4 == n3 && n1 == n2 && n2 == n5) || (n3 == n1 && n2 == n4 && n4 == n5) || (n3 == n2 && n1 == n4 && n4 == n5) || (n2 == n1 && n3 == n4 && n4 == n5))
        stat = "3 Equal and 2 Equal";
    else if ((n1 == n2 && n3 == n4) || (n1 == n2 && n3 == n5) || (n1 == n2 && n4 == n5) || (n1 == n3 && n2 == n4) || (n1 == n3 && n2 == n5) || (n1 == n3 && n4 == n5) || (n1 == n4 && n2 == n3) || (n1 == n4 && n2 == n5) || (n1 == n4 && n3 == n5) || (n1 == n5 && n2 == n3) || (n1 == n5 && n2 == n4) || (n1 == n5 && n3 == n4) || (n2 == n3 && n4 == n5) || (n2 == n4 && n3 == n5) || (n2 == n5 && n3 == n4))
        stat = "2 by 2, one alone :(";
    else if ((n1 == n2 && n2 == n3) || (n1 == n2 && n2 == n4) || (n1 == n2 && n2 == n5) || (n1 == n3 && n3 == n4) || (n1 == n3 && n3 == n5) || (n1 == n4 && n4 == n5) || (n2 == n3 && n3 == n4) || (n2 == n3 && n3 == n5) || (n3 == n4 && n4 == n5))
        stat = "Only 3 Equal";
    else if ((n1 == n2) || (n1 == n3) || (n1 == n4) || (n1 == n5) || (n2 == n3) || (n2 == n4) || (n2 == n5) || (n3 == n4) || (n3 == n5) || (n4 == n5))
        stat = "2 Equal";
    else
        stat = "NONE !!!";
    return stat;
}

void oSqua(int n)
{
    int k = 1, i, j;
    int S[17][17] = {0};
    for (; k <= n / 2 + 1; k++)
    {
        for (j = k - 1; j <= n - k; ++j)
        {
            for (i = k - 1; i <= n - k; ++i)
            {
                S[j][i] = k;
            }
        }
    }
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            cout << S[j][i] << "  ";
        }
        cout << endl;
    }
}

void calculate_pi()
{
    float sum = 4, i, k = -4;
    for (i = 3;; i += 2)
    {
        if (4 * (1 / i) < 0.00001)
            break;
        sum += k * (1 / i);
        k *= -1;
    }
    cout << "[ " << setprecision(4) << sum << " ]";
}

void yesterday(int y, int m, int d)
{

    d--;
    if (d)
    {
    }
    else if (m > 7)
    {
        m--;
        d = 30;
    }
    else if (m > 1)
    {
        m--;
        d = 31;
    }
    else if (y % 4)
    {
        y--;
        m = 12;
        d = 29;
    }
    else
    {
        y--;
        m = 12;
        d = 30;
    }

    cout << "Date: " << y << "/" << m << "/" << d;
}

string counter(int n)
{
    switch (n )
    {
        case 1:
        {return string ("st");
        break;}

        case 2:
        {
            return string("nd");
            break;
        }
        case 3:
        {
            return string ("rd");
            break;
        }
        default:
        {return string ("th");
        break;}
    }
}

void tamrin_structure()
{
    

}

/*
what I wanted to do for case 2...

 cout << "\n Enter the decimal number in the range\n(0 to 65535)\n";
            int deci;
            cin >> deci;
            char hex[4];
            cout << d2Hex(deci);
            cout << "0X";
            for (int i = 0; i < 4; ++i)
            {
                cout << hex[i] ;
            }
            break;


by returing an array in the function I'm calling (d2hex)
    return hex[4];
            */