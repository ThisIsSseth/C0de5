//C++ hello world code
//simple
#include <iostream>
//idk what above means //ok nevermind found out what it menas:
//#include<iostream>: #include is the pre-processor directive that is used to include files in our program. 
//Here we are including the iostream standard file which is necessary for the declarations of basic standard input/output library in  C++.
using namespace std; 
//idk what this one above means either 
//All elements of the standard C++ library are declared within a namespace.  Here we are using the std namespace.
int main()
//The execution of any C++ program starts with the main function, hence it is necessary to have a main function in your program.
//‘int’ is the return value of this function.
{
cout <<"Hello World!\n">>; 
return 0;
//We are returning 0 because we mentioned the return type of the main function as integer (int main). 
//A zero indicates that everything went fine and one indicates that something has gone wrong.
}
//Note the semicolon at the end of the return statement. Semicolons mark the end of most statements in C++. 
//They are easy to overlook but, when forgotten, can lead to mysterious compiler error messages.
//
