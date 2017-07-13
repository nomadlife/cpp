// Accessing the Data Members
// p158

#include <iostream>

using namespace std;
class Box
{
    public:
        double length; //Length of a box
        double breadth; //Breadth of a box
        double height; //Height of a box
};

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
    // =====================
    Box2.breadth

    //book 1 specification
    strcpy( Book1.title, "Learn c++ /programming");
    strcpy( Book1.author, "Chand Miyan");
    strcpy( Book1.subject, "C++ Programming");
    Book1.book_id = 6495407;

    //book 2 specification
    strcpy( Book2.title, "Telecom Biling");
    strcpy( Book2.author, "Yakit Singha");
    strcpy( Book2.subject, "Telecom");
    Book2.book_id=6495700;

    //print Book1 ifo
    printBook( &Book1);

    //Print Book2 info
    printBook( &Book2);

    return 0;
}

void printBook(struct Books *book)
{
    cout << "Book title :" << book->title << endl;
    cout << "Book author :" << book->author << endl;
    cout << "Book subject :" << book->subject << endl;
    cout << "Book is :" << book->book_id << endl;
}

