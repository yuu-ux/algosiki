#include <stdio.h>

long	double_factorial(int n)
{
	if (n < 3)
		return n;
	return n * double_factorial(n - 2);
}

int	main(void)
{
	int n;
	long res;
	scanf("%d", &n);
	res = double_factorial(n);
	printf("%ld\n", res);
	return 0;
}
