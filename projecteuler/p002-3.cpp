#include<iostream>
using namespace std;

int main()
{
unsigned long int a=1,b=2,c=0,sum=2;

while(1)
{
	if(c>=1000000) break;

	c=a+b;
	if(!(c%2)) sum += c;
	a=b;
	b=c;
}
cout<<sum;

return 0;
}