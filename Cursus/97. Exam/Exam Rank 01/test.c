#include <stdio.h>

void ft(int *i)
{
	(*i)++;
}
int main()
{
	int i;
	
	i = 0;
	
	ft(&i);
	
	printf("%d\n", i);
}
