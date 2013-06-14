#include <stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N);

int main()
{
	unsigned M, N;
	M = 21;
	N = 15;

	printf("%d\n", Gcd(M, N));

	return 0;
}

/* 求最大公约数 */
unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int Rem;
	while (N > 0) {
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}