// Pointer to C++ Classes

#include <iostream>
using namespace std;

class Box
{
    public:
    //constructor definition
    Box(double l=2.0, double b=2.0, double h=2.0 )
    {
        cout << "Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
    }
    double Volume()
    {
        return length * breadth * height;

    }
    
    private:
    double length;
    double breadth;
    double height;

};

//Main function
int main (void)
{
    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);
    Box *ptrBox;

    // Save the address of first object
    ptrBox = &Box1;

    //Now try to access a member using member access operator
    cout << "Volume of Box1:" << ptrBox->Volume() << endl;

    //Save the address of first object
    ptrBox = &Box2;

    //Now try to access a member using member access operator
    cout << "Volume of Box2:" << ptrBox->Volume() << endl;

    return 0;
}



