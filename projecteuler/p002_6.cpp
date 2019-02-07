#include <iostream>

int main()
{
	int a = 1, b = 1, temp = 0, sum = 0;
	while (b <= 4000000) {
		temp = a + b;
		a = b;
		b = temp;
		if (temp % 2 == 0) {
			sum += temp;
		}
	}
	std::cout << sum;
}