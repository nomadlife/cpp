#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace::std;

int main()
{
    ifstream fin;
    fin.open("hello.txt");

    char character;
    while (true)
    {
        fin.get(character);
        if(fin.fail())
        {
            break;
        }
        cout << character;
    }

}

