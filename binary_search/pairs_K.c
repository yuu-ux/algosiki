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

    //二分探索スタート
    long long count = 0;
    int left;
    int right;

    // 外側ループは要素数分繰り返す
    for (int i = 0; i < N; i++)
    {
        // 各要素数初めから終わりまでチェックするために、初期化する
        left = 0;
        right = N-1;
        // 内側ループで条件を満たす最小の値を確定させる
        while (left != right)
        {
            int mid = (right + left) / 2;
            // 条件を満たすなら今チェックしてる値も含めて右側を更新する
            // 条件を満たさないなら今チェックしてる値の次から探索したいため、leftをmid+1して探索範囲を狭める
            if (A[mid] >= K - A[i])
                right = mid;
            else
                left = mid + 1;
        }
        // 組み合わせの数は各要素の条件を満たす最小の値のインデックス値になる。
        // 条件を満たす最小の値より大きい要素は全て条件を満たすため、N-条件を満たす最小のインデックス値で条件を満たす組み合わせがいくつあるか求められる。
        count += N - left;
    }
    printf("%lld\n", count);
}
