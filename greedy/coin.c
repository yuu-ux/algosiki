#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int *A;
    int cnt;

    cnt = 0;
    scanf("%d", &N);
    A = (int *)malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++)
        scanf("%d", &A[i]);

    while (N != 0)
    {
        if (A[0] != 0 && 50 <= N)
        {
            N -= 50;
            A[0]--;
        }
        else if (A[1] != 0 && 10 <= N)
        {
            N -= 10;
            A[1]--;
        }
        else if (A[2] != 0 && 5 <= N)
        {
            N -= 5;
            A[2]--;
        }
        else if (A[3] != 0 && 1 <= N)
        {
            N -= 1;
            A[3]--;
        }
        cnt++;
    }
    printf("%d\n", cnt);
}
