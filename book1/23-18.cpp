// Static Function Members

#include <iostream>
using namespace std;

class Box
{
  public:
    static int objectCount; //only one variable.

    //constructor definition
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
        //Increase every time object is created
        objectCount++;
    }
    double Volume()
    {
        return length * breadth * height;
    }

    static int getCount()
    {
        return objectCount;
    }

  private:
    double length;
    double breadth;
    double height;
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void)
{
    //Print total nember of objects before creating object.
    cout << "Initial Stage Count:" << Box::getCount() << endl;

    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);

    //Now try to access a member using member access operator
    cout << "Final Stage Count:" << Box::getCount << endl;

    return 0;
}
