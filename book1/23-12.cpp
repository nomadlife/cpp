// Copy Constructor, use copy constructor

#include <iostream>
using namespace std;

class Line
{
  public:
    int getLength(void);
    Line(int len);         // simple constructor
    Line(const Line &obj); // copy constructor
    ~Line();               // destructor

  private:
    int *ptr;
};

//Constructor with parameter
Line::Line(int len)
{
    cout << "normal constuctor allocating ptr" << endl;
    //allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}
Line::Line(const Line &obj)
{
    cout << "copy constuctor allocating ptr" << endl;
    ptr = new int;
    *ptr = *obj.ptr; //copy the value
}
Line::~Line()
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}

//Member function definitions including consturctor
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "Length of line :" << obj.getLength() << endl;
}

int main()
{
    Line line1(10);
    Line line2 = line1; //this also calls copy constructor

    display(line1);
    display(line2);

    return 0;
}
