#include <stdio.h>

int sum(int n1, int n2)
{
	if (n1 > n2)
		return 0;
	return n1 + sum(n1 + 1, n2);
	return 0;
}

int main(void) {
	int n1;
	int n2;
	int res;

	scanf("%d", &n1);
	scanf("%d", &n2);
	res = sum(n1, n2);
	printf("%d\n", res);
	return 0;
}
