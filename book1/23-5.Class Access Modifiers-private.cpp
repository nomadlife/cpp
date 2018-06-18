// Class Access Modifiers - The Private Members
/* Practically, we define data in private section and
    functions in public section so that they can be
    called from outside of the class as shown in the
    following program. */

#include <iostream>
using namespace std;

class Box
{
    public:
        double length; 
        void setWidth( double wid );
        double getWidth( void );
    
    private:
        double width;

};

//member function definition
double Box::getWidth(void)
{
    return width;
}

void Box::setWidth( double wid )
{
    width = wid;
}

int main ()
{
    Box box;

    // set box length
    box.length = 10.0; // OK, length is public
    cout << "Lenth of box :" << box.length << endl;

    // set box width without member function
    // box.width = 10.0; Error, width is private
    box.setWidth(10.0); // OK: because length is puclic
    cout << "Width of line :" << box.getWidth() << endl;
    
    return 0;
}



