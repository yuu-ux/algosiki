#include <stdio.h>

int ft_sum(int n)
{
    if (n < 0)
        return 0;
    return n + ft_sum(n - 1);
}
int main(void)
{
    int N;
    int res;
    scanf("%d", &N);
    res = ft_sum(N);
    printf("%d\n", res);
}
