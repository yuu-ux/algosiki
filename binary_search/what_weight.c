#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    int W[N];
    int temp[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &W[i]);
    for (int i = 0; i < N; i++)
        temp[i] = W[i];
    qsort(temp, N, sizeof(int), compar);

    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (temp[mid] > W[i])
                right = mid;
            else
                left = mid + 1;
        }
        int ans = left - 1;
        printf("%d\n", ans);
    }
}
