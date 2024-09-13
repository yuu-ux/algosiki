#include <stdio.h>
#include <stdlib.h>
// A[i] + A[j] >= Kが成り立つ組み合わせをカウントする

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int N;
    int K;
    int *A;

    // 入力を受け取る
    scanf("%d %d", &N, &K);
    A = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    // 昇順にソートする
    qsort(A, N, sizeof(int), compare);

    long long count = 0;
    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N;
        while (left != right)
        {
            int mid = (left + right) / 2;
            if (A[mid] >= K - A[i])
                right = mid;
            else
                left = mid + 1;
        }
        count += N - left;
    }
    printf("%lld\n", count);
}
