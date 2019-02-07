/* Can you C it? */
#include <stdio.h>
int main()
{
	int sum = 2; // well, you know that the first even is 2 and it's outside of the loop
	int i0 = 1, i1 = 2, n = 1, f = 1;
	while (f < 4000000)
	{
		printf("\t%d", f);
		if (!(f & 1))
		{ /* It's even if the lowest bit of an int is zero ;-D */
			sum += f;
		}
		f = i0 + i1;
		i0 = i1;
		i1 = f;
		if (n++ % 5 == 0)
			printf("\n");
	}
	printf("\nsum of even=%d", sum);
	return 0;
}