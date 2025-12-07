#include <IOSTREAM>
#include <STDLIB.H> //rand & srand
#include <TIME.H> //time()
#include <IOMANIP>
using namespace std;

void create_arr(int *, int);
void random_value_2_arr(int *);
void print_arr(int *);
int highest_3_multiples(int *); // special for case 2
void fillDblank ( int []);
int main()
{
    int opt;
    do
    {
        cout << "Choose an option:\n1. Array of length n\n"
                "2. Create an array desirable\n"
                "length and find highest trio mutiplication\n"
                "3. The book library\n"
                "0. Exit(Run!)\n";

        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            int *arrptr1 = 0, n;
            cout << "Enter the length for a list:\n";
            cin >> n;
            create_arr(arrptr1, n);
            break;
        }
        case 2:
        {
            int *arrptr2 = NULL, n;
            cout << "Enter the length for a list:\n";
            cin >> n;
            create_arr(arrptr2, n);
            cout << "Choose an option:\n0. Give custom values\nelse. Random values";
            cin >> n;
            if (n)
            {
                if (arrptr2 != NULL)
                    random_value_2_arr(arrptr2);
                else
                {
                }
            }
            else
            {
                cout << "Enter " << (sizeof(arrptr2) / sizeof(int)) << " number of values:";
                int m;
                for (int i = 0; i < (sizeof(arrptr2) / sizeof(int)); ++i)
                {
                    cin >> m;
                    arrptr2[i] = m;
                }
            }
            cout << "And now,\nLadies and Gentlemen\nthis is the array:\n";
            print_arr(arrptr2);


            break;
        }
        
        case 3:
        {
            struct book { char name[10]; unsigned price;} list [10];

            
        }
        
        }
    }while (opt);

        return 0;
    }

    void create_arr(int *arrptr2, int n)
    {
        arrptr2 = (int *)malloc(n * (sizeof(int)));
        if (arrptr2 == NULL)
            cout << "Failed\n lol\n";
        else
            cout << "Success\n";
    }

    void random_value_2_arr(int *arrptr2)
    {
        srand(time(NULL));

        for (int i = 0; i < (sizeof(arrptr2) / sizeof(int)); ++i)
        {
            arrptr2[i] = rand() % 20;
        }
    }

    void print_arr(int *arrptr2)
    {
        if (!arrptr2)
        for (int i = 0; i < (sizeof(arrptr2) / sizeof(int)); ++i)
        {
            cout << arrptr2[i] << setw(2);
        }
    }

    int highest_3_multiples(int *)
    {
        int multi;
        return 0;
    }

    void fillDblank(int bklist[])
    {
        
    }
