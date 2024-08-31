#include <stdio.h>
#include <stdlib.h>

void    batch(int n, char *x)
{
    if (0 > n)
        return ;
    batch(n-1, x);
    printf("%c", x[n]);
    batch(n-1, x);
}

int main(void)
{
    int N;
    char *X;

    scanf("%d", &N);
    X = (char *)malloc(sizeof(char) * (N + 1));
    scanf("%s", X);
    batch(N-1, X);
    printf("\n");
    free(X);
}
