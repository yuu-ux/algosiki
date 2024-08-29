#include <stdio.h>

int total_sum(int A, int B)
{
    if (B == 1)
        return (1);
    if (B == A)
        return A;
    return B + total_sum(A, B-1);
}

int main(void)
{
    int A;
    int B;
    int res;

    scanf("%d %d", &A, &B);
    res = total_sum(A, B);
    printf("%d\n", res);
}
