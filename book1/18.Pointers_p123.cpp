//Pointer Comparisons
//p123

#include <iostream>
using namespace std;
const int MAX = 3;

int main ()
{
    int var[MAX] = {10, 100, 200};
    int *ptr;

    // let us have array address in pointer.
    ptr = var;
    int i=0;
    while (ptr <= &var[MAX-1])
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;

        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;

        // point to the next location
        ptr++;
        i++;
    }
    
    return 0;
}