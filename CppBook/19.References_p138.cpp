// References as Return Value
// p138

#include <iostream>
#include <ctime>


using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValue(int i)
{
    return vals[i]; // return a reference to the ith element
}

// main function to call above defined function
int main ()
{
    cout << "Value before change" << endl;
    for (int i=0; i<5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    
    setValue(1) = 20.33; //change 2nd element
    setValue(3) = 70.8;  //change 4th element

    cout << "Value after change" <<endl;
    for (int i=0; i<5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    
    return 0;
}

