// Using Initialization Lists to Initialize Fields 

#include <iostream>
using namespace std;

class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        Line(double len); // This is the constructor (with parameter)

    private:
    double length;

};

//Constructor define with parameter
Line::Line(double len):length(len)
{
    cout << "Object is being created, elngth =" << len << endl;
}

//Member function definitions including consturctor
void Line::setLength( double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}

//Main function for the program
int main ()
{
    Line line(10.0);

    //get initially set length by Constructor
    cout << "Initial Length of line :" << line.getLength() <<endl;

    // set line length
    line.setLength(6.0);
    cout << "Length of line :" << line.getLength() << endl;

    return 0;
}



