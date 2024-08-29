#include <stdio.h>

long factorial(int n)
{
    if (n < 3)
    {
        if (n == 2)
            return 2;
        else
            return 1;
    }
    return (n * factorial(n - 2));
}
int main(void)
{
    int N;
    long res;

    scanf("%d", &N);
    res = factorial(N);
    printf("%ld\n", res);
}
