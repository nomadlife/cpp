#include <iostream> 

int main()
{
	int a = 1, sum = 2, b = 2, i, c;
	for (i = 3; i <= 4000000; i = c)
	{
		c = a + b;
		a = b;
		b = c;
		if (c % 2 == 0)
			sum += c;
	}
	std::cout << sum;
}