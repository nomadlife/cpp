// person.cpp
//
#include "person.h"
void Person::print() const
{
    std::cout << "Name : ";
    name.print();
    std::cout << " | Phone : ";
    phone.print();
}