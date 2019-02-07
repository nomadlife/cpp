#include <bits/stdc++.h>

using namespace std;

long long int sum = 0;

int fib(int f, int s)
{
	if (!(f & 1))
		sum += f;
	if (s > 4000000)
		return sum;
	int n = f + s;
	f = s;
	return fib(f, n);
}

int main()
{
	cout << fib(1, 2) << endl;
	return 0;
}