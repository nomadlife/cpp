#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace::std;

int main()
{
    ifstream fin;
    fin.open("hello.txt");

    string name;
    float balance;
    while (!fin.eof())
    {
        fin >> name >> balance ;
        cout << name << ":$" << balance << endl;
    }

    fin.close();
}

