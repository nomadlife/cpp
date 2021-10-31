// telphonebook.cpp
//
#include "telphonebook.h"

static const int MAXNAMELEN = 20;
static const int MAXPHONELEN = 20;
static const int MAXADDRLEN = 50;
static const int MAXPOSLEN = 30;

void TelPhoneBook::insert()
{
    char name[MAXNAMELEN];
    char phone[MAXPHONELEN];
    char addr[MAXADDRLEN];
    char pos[MAXPOSLEN];
    Person *p;
    int input;
    std::cout << "Whtat type of person(1.Friend, 2.Companion) : ";
    std::cin >> input;
    std::cout << "Input Name : ";
    std::cin >> name;
    std::cout << "Input Phone : ";
    std::cin >> phone;
    switch (input)
    {
    case 1:
        std::cout << "Input Address : ";
        std::cin >> addr;
        p = new Friend(String(name), String(phone), String(addr));
        break;
    case 2:
        std::cout << "Input Position : ";
        std::cin >> pos;
        p = new Companion(String(name), String(phone), String(pos));
        break;
    default:
        return;
    }
    phoneList.insert(p);
}

void TelPhoneBook::remove()
{
    char name[MAXNAMELEN];
    std::cout << "Input Name (for removal) : ";
    std::cin >> name;
    for (int i = 0; i < phoneList.getSize(); i++)
    {
        if (phoneList.getItem(i)->getName().isEqual(String(name)))
        {
            phoneList.remove(i);
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
    for (int i = 0; i < phoneList.getSize(); i++)
    {
        if (phoneList.getItem(i)->getName().isEqual(String(name)))
        {
            phoneList.getItem(i)->print();
            return;
        }
    }
    std::cout << "No person object found." << std::endl;
}

void TelPhoneBook::printAll()
{
    for (int i = 0; i < phoneList.getSize(); i++)
        phoneList.getItem(i)->print();
}
