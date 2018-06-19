//Using Pointers in C++

#include <iostream>
using namespace std;

string title[]=
{
    "Null Point",
    "Pointer arithmetic",
    "Pointer vs array",
    "Array of pointers",
    "Pointer to pointer",
    "Passing pointers to functions",
    "Return pointer from functions"
};

string contents[]={
    "C++ supports null pointer, which is a constantwith a value of zero defined in several libraries",
    "There are four arithmetic operators that can be used on pointers:++,--,+,-",
    "There is a close relationship betweeen poitners and arrays",
    "You can define arrays to hold a number of pointers",
    "C++ allows you to have pointer on a pointer and so on",
    "Passing an argument by reference or by address both enable the passed argument to be changed in the calling function by the called function",
    "C++ allow a function to return a pointer to local variable, static variable and dynamically allocated memory as well"
};

int main ()
{
    for(int i=0;i<7;i++)
    {
        cout << i<<":"<<title[i] << endl;
    }
    
int var = 20; // actual variable declaration.
int *ip; // pointer variable
ip = &var; // store address of var in pointer variable
cout << "Value of var variable: ";
cout << var << endl;
// print the address stored in ip pointer variable
cout << "Address stored in ip variable: ";
cout << ip << endl;
// access the value at the address available in pointer
cout << "Value of *ip variable: ";
cout << *ip << endl;
return 0;
}