// main.cpp
//
#include <iostream>
#include <stdlib.h>
#include "telphonebook.h"

void printMenu()
{
    std::cout << std::endl
              << std::endl
              << std::endl;
    std::cout << "    [Menu] " << std::endl;
    std::cout << " 1. insert " << std::endl;
    std::cout << " 2. remove " << std::endl;
    std::cout << " 3. search " << std::endl;
    std::cout << " 4. printall " << std::endl;
    std::cout << " 5. exit " << std::endl;
}
int main()
{
    TelPhoneBook tpb;
    int input;
    while (1)
    {
        printMenu();
        std::cout << "Choose the item : ";
        std::cin >> input;
        switch (input)
        {
        case 1:
            tpb.insert();
            break;
        case 2:
            tpb.remove();
            break;
        case 3:
            tpb.search();
            break;
        case 4:
            tpb.printAll();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}