





#include <stdio.h>

void bits(char c)
{
	int i;
	unsigned int a;

	i = 8;
	while (i >= 0)
	{
		a = (c >> i) & 1;
	    printf("%d", a);
		i--;
	}
    printf("\n");
}

int main()
{
    bits('a');
}