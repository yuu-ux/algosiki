#include <stdlib.h>
#include <stdio.h>

// 用意できる紐の長さの最大値を求める
// K本用意するのに紐の長さの最大
int f(double x, double *L, int N)
{
    int ans;

    ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += (int)(L[i] / x);
    }
    return ans;
}

int main(void)
{
    int N;
    int K;
    double *L;

    scanf("%d %d", &N, &K);
    L = (double *)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++)
        scanf("%lf", &L[i]);

    double left;
    double right;

    left = 0;
    right = 200000;

    while (right - left > 0.000001)
    {
        double mid = (right + left) / 2;
        if (f(mid, L, N) >= K)
            left = mid;
        else
            right = mid;
    }
    printf("%.10f\n", left);
    return 0;
}
