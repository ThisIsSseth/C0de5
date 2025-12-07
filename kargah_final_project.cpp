#include <IOSTREAM>

using namespace std;

void add(int, int &, int *);
void show(int &, int *);
// int high(int &, int *);
// int low(int &, int *);
int high(int, int *);
int low(int, int *);
float avg(int &, int *);
void pass(int &, int *);
void sort(int &, int *);
int search(int, int &, int *);

int main()
{
    int score[60], entry, max = 0; // max is number of scores entered by user, max::(0 - 60)
    int *scorepntr = &score[60];

    do
    {
        cout << "\n______\nmax=" << max << "\n1. Add grade\n"
                                           "2. Show all score\n"
                                           "3. Show highest score\n" // برگشتی
                                           "4. Show lowest\n"        // برکشتی
                                           "5. Show average score\n"
                                           "6. Show passed students\n"
                                           "7. Sort scores\n"
                                           "8. Search for a score\n"
                                           "0. Exit\n";
        cin >> entry;

        switch (entry)
        {
        case 1: // add
        {
            int entry1;
            cout << "Enter score:\n"
                    "(of 100)\n";
            cin >> entry1;
            if (entry1 > 100)
                cout << "try again\n";
            else
            {
                add(entry1, max, scorepntr);
            }
            break;
        }
        case 2: // show all
        {
            show(max, scorepntr);
            break;
        }
        case 3: // highest score
        {
            cout << "The highest score is: " << high(max - 1, scorepntr);
            // high(max, scorepntr);
            break;
        }
        case 4: // lowest score
        {
            cout << "The lowest score is: " << low(max, scorepntr);
            break;
        }
        case 5: //...
        {
            cout << "The average of all scores is: " << avg(max, scorepntr);
            break;
        }
        case 6: // tells which students have passed
        {
            pass(max, scorepntr);
            break;
        }
        case 7: // sorts the scores
        {
            sort(max, scorepntr);
            break;
        }
        case 8: // searches
        {
            int entry;
            cout << "Enter data to search for:\n";
            cin >> entry;
            int loc = search(entry, max, scorepntr); // location
            if (loc == -1)
                cout << "Couldn't find what your looking for :(";
            else
                cout << "The location of inquiry is: " << loc;
            break;
        }

        case 0:
        {
            return 0;
        }

        default:
            break;
        }

    } while (true);

    return 0;
}

// max is the number of written elements. max = last, max = the arrays last block +1
// e.g: max 5, arr[4]

void add(int entry, int &last, int *arr)
{
    if (last < 60){
        arr[last++] = entry;
    cout << "Done\n";}
    else cout << "No sapce to add more";
}

void show(int &last, int *arr)
{
    cout << "[ ";
    for (int i = 0; i < last; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]";
}

// // int high(int &last, int *arr)
// {
//     int maximum = arr[0];
//     for (int i = 0; i < last - 1; i++)
//         if (arr[i] < arr[i + 1])
//             maximum = arr[i + 1];
//     return maximum;
// }

// // int low(int &last, int *arr)
// {
//     int minimum = arr[0];
//     for (int i = 0; i < last - 1; i++)
//         if (arr[i] > arr[i + 1])
//             minimum = arr[i + 1];
//     return minimum;
// }

int high(int last, int *arr)
{
    int highv;
    if (last > 0)
        highv = high(last - 1, arr);
    else
        highv = arr[last];
    if (highv < arr[last])
        highv = arr[last];
    return highv;
}

int low(int last, int *arr)
{
    int lowv; //lowest as a variable
    if (last > 0)
        lowv = low(last - 1, arr);
    else
        lowv = arr[last];
    if (lowv > arr[last])
        lowv = arr[last];
    return lowv;
}

float avg(int &last, int *arr)
{
    int sum = 0;
    for (int i = 0; i < last; i++)
        sum += arr[i];

    return ((float)sum / last);
}

void pass(int &last, int *arr)
{
    for (int i = 0; i < last; i++)
    {
        if (arr[i] >= 50)
            cout << "\nStudent no." << i + 1 << " passed.";
    }
}

void sort(int &original_last, int *arr)
{
    int last = original_last;
    int temp;
    for (int k = 0; k < --last; k++)
        for (int i = k; i < last - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
}

int search(int entry, int &last, int *arr)
{
    int res = -1;
    for (int i = 0; i < last || res < 0; i++)
        if (entry == arr[i])
            res = i;
    return res;
}
