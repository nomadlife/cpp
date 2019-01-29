// The Class Destructor

#include <iostream>
using namespace std;

class Line
{
  public:
    void setLength(double len);
    double getLength(void);
    Line();  // This is the constructor
    ~Line(); // This is the destructor

  private:
    double length;
};

//Constructor with parameter
Line::Line(void)
{
    cout << "Object is being created" << endl;
}

Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}

//Member function definitions including consturctor
void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}

int main()
{
    Line line;

    // set line length
    line.setLength(6.0);
    cout << "Length of line :" << line.getLength() << endl;

    return 0;
}
