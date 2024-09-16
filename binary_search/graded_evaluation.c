#include <stdio.h>
#include <stdlib.h>
// input
// N: 従業員
// K: 基準スコア数
// A: 従業員のスコア
// x: 基準スコア
int main(void)
{
    int N;
    int K;
    scanf("%d %d", &N, &K);
    int *A;
    int *x;

    // 入力を受け取る
    A = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    x = (int *)malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++)
        scanf("%d", &x[i]);

    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = K;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (A[i] < x[mid])
                right = mid;
            else
                left = mid + 1;
        }
        int ans = left;
        printf("%d\n", ans);
    }
}
