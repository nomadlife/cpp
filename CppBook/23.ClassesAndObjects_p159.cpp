// Classes & Objects in Detail
// p159
#include <iostream>
using namespace std;

int main ()
{
    string concepts[] =
    {
        "class member functions",
        "class access modifiers",
        "Constructor & destructor",
        "C++ copy constructor",
        "C++ friend functions",
        "C++ inline functoins",
        "The this pointer in C++",
        "Pointer to C++ classes",
        "static members of a class"
    };

    string description[] =
    {
        "A member function of a class is a function \
        that has its definition or its prototype \
        within the class difinition like any other variable.",
        
        "A class member can eb defined as public, \
        private or protected. By default members \
        would be assumed as private.",

        "A class constructor is a special function \
        in a class that is called when a new object of \
        the class is created. A destructor is also \
        a special function which is called when created \
        object is deleted.",

        "The copy constructor is a constructor which \
        creates an object by initializing it with an \
        object of the same class, which has been created \
        preciously"

        "Afriendfunction is permitted full access to private \
        and protected members of a class.",

        "With an inline function, the compiler tries \
        to expand the code in the body of the function \
        in place of a call to the function.",

        "Every object has a special pointer this which \
        points to the object itself.",

        "A pointer to a class is done exactly the same way \
        a pointer to a structure is. In fact a class is \
        really just a structure with functions in it.",

        "Both data members and function members of \
        a class can be declared as static."
    };
    
    for(int i=0; i<9; i++)
    {
        cout << "===" << i+1 << "th concept is ";
        cout << concepts[i] << endl;
        cout << description[i] << endl;
    }
    return 0;
}
