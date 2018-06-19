#include <iostream>
using namespace std;

int main()
{
    int Divided = 0;
    for(int i = 0; i < 1000; i++)
    {
            if(i % 3 == 0)
            {
                 Divided = Divided + i;
                 cout<<i <<": is dividable\n";
            }
            else if(i % 5 == 0)
            {
                 Divided = Divided + i;
                 cout<<i <<": is dividable\n";
            }
    }
    cout<<"Sum: " <<Divided;
    cin.get();
    return 0;
}