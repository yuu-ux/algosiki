#include <stdio.h>

int main(void)
{
    int N;
    int cnt;
    cnt = 0;
    scanf("%d", &N);

    while (N)
    {
        if (N % 3 == 0)
            N /= 3;
        else
            N -= 1;
        cnt++;
    }
    printf("%d\n", cnt);
}
