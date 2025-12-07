// I explore pointers, random function, C functions
// ** => scanf("%d", &n); **("")(,)(&)(;)!!!

#include <STDIO.H>
#include <STDLIB.H>

void createMatrix1d();
void createMatrix2d();
int main()
{
    int entry;
    while (true)
    {
        
        printf("Choose an option:\n"
               "1. Make 1d Matrix\n"
               "2. Make 2d Matrix\n"
               "3. Roll a dice\n"
               "4. Experiments w/ pointers\n"
               "0. Exit\n");
        scanf("%d", &entry);
        switch (entry)
        {
        case 1:
        {
            createMatrix1d();
            break;
        }

        case 2:
        {
            createMatrix2d();
            break; 
        }

        case 3:
        {
            int n;
            do
            {

                int i = 1 + (rand() % 6);
                printf(" %2d\nRoll again?\n1. Yes\n", i);
                scanf("%d", &n);
            } while (n == 1);
            break;
        }

case 4:
{
    int *ptr1, *ptr2, *ptr3, A = 7, B = 18;
    ptr1 = &A;
    // *ptr2 = &A; //Error: *ptr2 is int and &A is an address (int *)
   // *ptr3 = A; //Error: *ptr3 (int) is not pointing to anything but is to get a value 
    printf("ptr1 = &A => *ptr1=%d\nptr1 =%d",*ptr1, ptr1); /*dereferencing is done by puting a * behind the name of a pointer and makes it go back one step toward its origin,
    closer to the value it is pointing at and further from itself*/
}

        case 0:
        {
            return 0;
        }

        default:
            break;
        }
    }

    return 0;
}

void createMatrix1d()
{
    int *nptr, n;
    printf("Enter length:\n");
    scanf("%d",&n);
    nptr = new int[n];
    for (int i = 0; i < n; i ++)
    {
        nptr[i] = (rand() % 10);
    }
    printf("[ ");
    for (i = 0; i < n; i ++)
    {
        // printf ("%d \n", nptr [i]);
        printf ("%2d", *(nptr + i));
    }
    printf(" ]");


// ?
    // int **m = int *mr[n];
    // *mr = int mc[n] = {0};
    //     for (int i = 0; i < n; i ++)
    //     for (int j = 0; j < n; j ++)
    //     print ( "%2d", m[i][j], "\n");
}

void createMatrix2d()
{
    int **_2dptr, d;
    do {
        
    printf ("Enter length:\n");
    scanf ("%d", &d);
    _2dptr = (int  **) /*<type casting*/malloc(d * sizeof(int *)); 
                                                                        // printf ("%a", *_2dptr);
    if (_2dptr == NULL)
         printf("Failure, choose smaller length.\n;");
    }while (_2dptr == NULL);

    for (int i = 0; i < d; i ++)
    {
        *(_2dptr + i) = (int *)malloc(d * (sizeof(int)));
        for (int j = 0; j < d; j++)
        {
            // _2dptr[i][j] = rand() %10 ;
            *(*(_2dptr + i) + j) = rand() % 10; 
        }
    }
printf ("Success\nDo you want to see it?\n0. Yes\nelse = no");
int ans;
scanf("%d", &ans);
if (!ans)
{
    for (i = 0; i < d; i ++)
    for (int j = 0; j < d; j ++)
    {
        printf("%d", *(*(_2dptr + i)+ j));
    }
}
}


/*
 => scanf("%d", &n); **("")(,)(&)(;)!!!
 tags:
 %u for unsigned int
 %a address
%d decimal

RANDOM
srand() and rand(): in <stdlib.h>
rand() is int. Function rand actually generates pseudorandom numbers.
To acrually create random numbers first get unsigned as seed and do this: srand(seed); and then use rand;
To randomize without entering a seed each time, use a statement like:
srand( time( NULL ) ); needs <time.h>

*ptr2 = &A; //Error: *ptr2 is int and &A is an address (int *)
*ptr3 = A; //Error: *ptr3 (int) is not pointing to anything but is to get a value 

dereferencing is done by puting a * behind the name of a pointer and makes it go back one step toward its origin,
closer to the value it is pointing at and further from itself

            *(*(_2dptr + i) + j) = rand() % 10;
_2dptr is an address to a pointer that points to the first element of its array (it points to the first block of an array of pointers)
by adding i to it, it goes to the i-th row (it goes to the i-th block in the array of pointers)

    */