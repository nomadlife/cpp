// Class member functions

#include <iostream>

using namespace std;

class Box
{
    public:
        double length; //Length of a box
        double breadth; //Breadth of a box
        double height; //Height of a box

        //member function declaration
        double getVolume( void );
        void setLength( double len );
        void setBreadth( double bre );
        void setHeight( double hei );
};


//member function definition
double Box::getVolume(void)
{
    return length * breadth * height;
}

void Box::setLength( double len )
{
    length = len;
}

void Box::setBreadth( double bre )
{
    breadth = bre;
}

void Box::setHeight( double hei )
{
    height = hei;
}

int main ()
{
    Box Box1;
    Box Box2;
    double volume = 0.0;

    // box1 specification
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    //box 2 specification
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth  = 13.0;

    //volume of box1
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;

    //volume of box 2
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;
    
    return 0;
}



