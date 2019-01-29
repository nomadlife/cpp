// Creating References in C++

#include <iostream>
// #include <ctime>
// #include <cstdlib> // Example error. added.

using namespace std;

//main function to call above defined function.
int main()
{
    //declare simple variables
    int i;
    double d;

    int &r = i;
    double &s = d;

    i = 5;
    cout << "Value of i: " << i << endl;
    cout << "Value of i reference : " << r << endl;

    d = 11.7;

    cout << "Value of d :" << d << endl;
    cout << "Value of d reference :" << s << endl;

    i = 6;
    cout << "Value of i: " << i << endl;
    cout << "Value of i reference : " << r << endl;

    d = 12.7;

    cout << "Value of d :" << d << endl;
    cout << "Value of d reference :" << s << endl;

    return 0;
}

// References as parameters
/* C++ supports passing references as function
parameter more safely than parameters. */

// Reference as return value
/* You can return reference from a C++ function */
