//Call by Reference
//function definition to swap the value.

#include <iostream>
using namespace std;


//function declaration
void swap(int &x, int &y);

int main()
{
    //local vatiable declaration:
    int a=100;
    int b=200;

    cout << "Before swap, value of a :" << a << endl;
    cout << "Before swap, value of b :" << b << endl;

    // calling a function to swap the values.
    // &a is address of variable a
    // &b is address of variable b
    swap(a,b);

    cout << "After swap, value of a:" << a << endl;
    cout << "After swap, value of b:" << b << endl;

    return 0;
}


void swap(int &x, int &y)
{
    int temp;

    temp = x; 
    x= y;
    y= temp;

    return;

}
