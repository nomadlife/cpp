#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAXNAMELEN 20
#define MAXPHONELEN 20
#define MAXPERSONNUM 100

typedef struct
{
    char name[MAXNAMELEN];
    char phone[MAXPHONELEN];
} Person;

Person phoneList[MAXPERSONNUM];
int pidx = 0;

void insert()
{
    char name[MAXNAMELEN];
    char phone[MAXPHONELEN];
    std::cout << "Input Name : ";
    std::cin >> name;
    std::cout << "Input Phone : ";
    std::cin >> phone;
    if (pidx < MAXPERSONNUM)
    {
        strcpy(phoneList[pidx].name, name);
        strcpy(phoneList[pidx].phone, phone);
        pidx++;
        std::cout << "Insert O.K. " << std::endl;
    }
    else
        std::cout << "Person Storage is Full" << std::endl;
}

void remove()
{
    char name[MAXNAMELEN];
    std::cout << "Input Name (for removal) : ";
    std::cin >> name;
    for (int i = 0; i < pidx; i++)
    {
        if (strcmp(phoneList[i].name, name) == 0)
        {
            for (int j = i; j < pidx - 1; j++)
            {
                strcpy(phoneList[j].name, phoneList[j + 1].name);
                strcpy(phoneList[j].phone, phoneList[j + 1].phone);
            }
            pidx--;
            std::cout << i + 1 << "th person object removed." << std::endl;
            return;
        }
    }
    std::cout << "No person object found." << std::endl;
}

void search()
{
    char name[MAXNAMELEN];
    std::cout << "Input Name (for search) : ";
    std::cin >> name;
    for (int i = 0; i < pidx; i++)
    {
        if (strcmp(phoneList[i].name, name) == 0)
        {
            std::cout << "Name : " << phoneList[i].name << " | Phone : "
                      << phoneList[i].phone << std::endl;
            return;
        }
    }
    std::cout << "No person object found." << std::endl;
}

void printAll()
{
    for (int i = 0; i < pidx; i++)
        std::cout << "Name : " << phoneList[i].name << " | Phone : "
                  << phoneList[i].phone << std::endl;
}

void printMenu()
{
    std::cout << std::endl
              << std::endl
              << std::endl;
    std::cout << "      [Menu] " << std::endl;
    std::cout << " 1. insert " << std::endl;
    std::cout << " 2. remove " << std::endl;
    std::cout << " 3. search " << std::endl;
    std::cout << " 4. printall " << std::endl;
    std::cout << " 5. exit " << std::endl;
}

int main()
{
    int input;
    while (1)
    {
        printMenu();
        std::cout << "Choose the item : ";
        std::cin >> input;
        switch (input)
        {
        case 1:
            insert();
            break;
        case 2:
            remove();
            break;
        case 3:
            search();
            break;
        case 4:
            printAll();
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}