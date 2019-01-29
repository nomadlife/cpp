// Accessing Structure Members

#include <iostream>
#include <cstring>

using namespace std;

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main()
{
    struct Books Book[] = {'Book1', 'Book2'}; //Declare Book1 of type Book
    //struct Books Book2; //Declare Book2 of type Book

    //book 1 specification
    strcpy(Book[1].title, "Learn c++ /programming");
    strcpy(Book[1].author, "Chand Miyan");
    strcpy(Book[1].subject, "C++ Programming");
    Book[1].book_id = 6495407;

    //book 2 specification
    strcpy(Book[2].title, "Telecom Biling");
    strcpy(Book[2].author, "Yakit Singha");
    strcpy(Book[2].subject, "Telecom");
    Book[2].book_id = 6495700;

    //int* Arr[]={&Book1, &Book2};
    for (int i = 0; i < 2; ++i)
    {
        //Print Book1 info
        cout << "Book " << i + 1 << " title : " << Book[i].title << endl;
        //cout << "Book "<< i+1 <<" author : " << *Arr[i].author << endl;
        //cout << "Book "<< i+1 <<" subject : " << *Arr[i].subject << endl;
        //cout << "Book "<< i+1 <<" id : " << *Arr[i].book_id << endl;
    }

    return 0;
}
