// Class Access Modifiers :: The Public Members
// p164

#include <iostream>

using namespace std;

class Line
{
    public:
        double length; 
        void setLength( double len );
        double getLength( void );
        
};

//member function definition
double Line::getLength(void)
{
    return length;
}

void Line::setLength( double len )
{
    length = len;
}

int main ()
{
    Line line;

    // set line length
    line.setLength(6.0);
    cout << "Lenth of line :" << line.getLength() << endl;

    // set line length without member function
    line.length = 10.0; // OK: because length is puclic
    cout << "Length of line :" << line.length << endl;
    return 0;
}



