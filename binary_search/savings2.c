#include <stdio.h>
#include <stdlib.h>

long    f(long x)
{
    return x * (x + 1) / 2;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    long *X = (long *)malloc(sizeof(long) * N);
    for (int i = 0; i < N; i++)
        scanf("%ld", &X[i]);

    for (int i = 0; i < N; i++)
    {
        long left = 0;
        long right = 2000000000;
        while (left < right)
        {
            long mid = left + (right - left) / 2;
            if (f(mid) >= X[i])
                right = mid;
            else
                left = mid + 1;
        }
        printf("%ld\n", left);
    }
}
