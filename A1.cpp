#include <iostream> //directive to the C preprocessor
/*Lines beginning with # are processed by the preprocessor before the program is compiled */
#include <IOSTREAM.H>
#include <STDLIB.H>
#include <MATH.H>
#include <ctime>

#define SIZE 11

void print_array (int * array, int size);
int* sort_tech01( int *, int);
struct sub_arrays divide(int*, int);
int* merge (int*, int, int*, int);
int get_size(int*);



struct sub_arrays
{
    int * a1;
    int* a2;
};


int main (void){
    // const int SIZE = 11;
    // // SIZE = 100; 
    int main_array[SIZE];

    srand(time(NULL));

    for ( int i = 0; i < SIZE; ++i){
        main_array[i] = rand() % 100;
    }

    print_array( main_array, SIZE);

    cout << "\n ------- \n";

   print_array(divide(main_array, SIZE).a1, SIZE/2);
   print_array(divide(main_array, SIZE).a2, SIZE - SIZE/2);


    cout << "\n ------- \nSorting...\n";

    print_array(sort_tech01(main_array, SIZE), SIZE);

    return 0;
}

void print_array (int * array, int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}

int *sort_tech01(int *main_array , int size)
{
    if (size == 1){
        return main_array;
    }
    else {
        struct sub_arrays sb = divide(main_array, size);
        int* a1 = sort_tech01(sb.a1, get_size(sb.a1));
        int* a2 = sort_tech01(sb.a2, get_size(sb.a2));
        
        int* sorted_array = merge(a1, get_size(a1), a2, get_size(a2));
        return sorted_array;

    }



    return NULL;
}

sub_arrays divide(int * array, int size)
{
    int f_size = size/2;
    int s_size = size - f_size;
    int* first_array = new int [f_size];
    int* second_array = new int [s_size];

    int i = 0;
    for (i; i < f_size; i++){
        first_array[i] = array[i];
    }
    for (i = f_size0; i < s_size + f_size; i ++){
        second_array[i - f_size] = array [i];
    }

    sub_arrays arrays;
    arrays.a1 = first_array;
    arrays.a2 = second_array;

    return arrays;

    // return sub_arrays = {first_array, second_array}; //??
}

int *merge(int * sub_array1, int size1, int * sub_array2, int size2)
{
    int* main_array = new int[size1 + size2];
    int min1 = sub_array1[0];
    int min2 = sub_array2[0];
    int indexmain = 0;
    int index1 = 0;
    int index2 = 0;
    while (index1 < size1 && index2 < size2){
        if(min1 > min2){
            main_array[indexmain] = min1;
            index1 ++;
            min1 = sub_array1[index1];
        }
        else {
            main_array[indexmain] = min2;
            index2 ++;
            min2 = sub_array2[index2];
        }
            indexmain ++;
    }

    if (index1 < size1){
        for (index2; index2 < size2; index2 ++, indexmain++){
            main_array[indexmain] = sub_array2[index2];
        }
    } else {
        for (index1; index1 < size1; index1 ++, indexmain++){
            main_array[indexmain] = sub_array1[index1];
        }
    }    
    return main_array;
}

int get_size(int * int_array)
{
    return(int) sizeof (int_array)/sizeof(int);
}

/* Output:
41
67        
34        
0
69        
24        
78        
58        
62        
64        
5

 -------  
41        
67        
34        
0
69        

 -------  
Sorting...
41        
0
17        
33        
24        
0
0
0
0
0
33
 */