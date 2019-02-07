#include <iostream>
// less than and greater than are disabled

using namespace std;

int main(int argc, char** argv)
{
    unsigned int sum = 0;
    for(int i = 1; i < 1001; ++i)
	{
        if(!(i % 3) && !(i % 5))
            sum += i;
	}
    cout << sum << endl;
    return 0;
}
