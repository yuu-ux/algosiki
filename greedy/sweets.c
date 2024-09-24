#include <stdio.h>

void f(int N, int *cnt)
{
    if (N == 0)
        return ;
    if (N % 2 == 0) {
        (*cnt)++;
        f(N / 2, cnt);
    } else {
        (*cnt)++;
        f(N - 1, cnt);
    }
}

int main(void)
{
    int N;
    int cnt;

    cnt = 0;
    scanf("%d", &N);
    f(N, &cnt);
    printf("%d\n", cnt);
}
