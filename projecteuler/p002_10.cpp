#include <stdio.h>

void main()
{
  int i;
  int a=1,b=2,c;
  double sum=2;
  for(i=1;;i++)
  {
  	c=a+b;
  	if(c>4000000)
  	{
  		break;
  	}
  	if(c%2==0)
  		{
  			sum=sum+c;
  		}
  	
    a=b;
    b=c;
  }
  printf("%f",sum);
}