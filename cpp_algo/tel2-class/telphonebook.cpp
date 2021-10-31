// telphonebook.cpp
//
#include "telphonebook.h"

void TelPhoneBook::insert()
{
    char name[MAXNAMELEN];
    char phone[MAXPHONELEN];
    std::cout << "Input Name : ";
    std::cin >> name;
    std::cout << "Input Phone : ";
    std::cin >> phone;
    if (pidx < MAXPERSONNUM)
    {
        phoneList[pidx++] = Person(name, phone);
        std::cout << "Insert O.K. " << std::endl;
    }
    else
        std::cout << "Person Storage is Full" << std::endl;
}

void TelPhoneBook::remove()
{
    char name[MAXNAMELEN];
    std::cout << "Input Name (for removal) : ";
    std::cin >> name;
    for (int i = 0; i < pidx; i++)
    {
        if (strcmp(phoneList[i].getName(), name) == 0)
        {
            for (int j = i; j < pidx - 1; j++)

                phoneList[j] = phoneList[j + 1];
            pidx--;
            std::cout << i + 1 << "th person object removed." << std::endl;
            return;
        }
    }
    std::cout << "No person object found." << std::endl;
}

void TelPhoneBook::search()
{
    char name[MAXNAMELEN];
    std::cout << "Input Name (for search) : ";
    std::cin >> name;
    for (int i = 0; i < pidx; i++)
    {
        if (strcmp(phoneList[i].getName(), name) == 0)
        {
            phoneList[i].print();
            return;
        }
    }
    std::cout << "No person object found." << std::endl;
}

void TelPhoneBook::printAll()
{
    for (int i = 0; i < pidx; i++)
        phoneList[i].print();
}