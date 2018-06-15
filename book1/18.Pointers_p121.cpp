//Decrementing a Pointer

#include <iostream>
using namespace std;
const int MAX = 3;

int main ()
{
    int var[MAX] = {10, 100, 200};
    int *ptr;

    // let us have array address in pointer.
    ptr = &var[MAX-1];
    for (int i = MAX; i > 0; i--)
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        // point to the next location
        ptr--;
    }
    
    return 0;
}