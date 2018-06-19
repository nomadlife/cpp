#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int s = 0;
	for (int i = 1, j = 2; j < 1000000; j += i, i = j-i)
		if (j % 2 == 0)
			s += j;

	cout << s << endl;
	return 0;
}