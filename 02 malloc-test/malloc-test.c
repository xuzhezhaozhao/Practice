#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p;
	p = malloc(10);
	*p = 10;
	printf("*p = %d\n", *p);
	printf("sizeof(int) = %ld, sizeof(int *) = %ld\n", 
			sizeof(int), sizeof(int *));
	return 0;
}
