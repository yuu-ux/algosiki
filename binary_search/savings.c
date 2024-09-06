#include <stdio.h>
#define Tolerance 0.01

// N:預けた額
// 利子によってX倍になる
// 5年後にM円になるXを求める
double f(double N, double X)
{
    double res = N + 1;
    for (int i = 0; i < 5; i++)
    {
        res = res * X + 1;
    }
    return res;
}

int main(void)
{
    double N;
    double M;
    double left;
    double right;
    double mid;
    double res;

    scanf("%lf %lf", &N, &M);
    left = 0;
    right = 100;
    while (right - left > Tolerance)
    {
        mid = (left + right) / 2;
        if (f(N, mid) < M)
            left = mid;
        else
            right = mid;
    }

    res = left;
    printf("%lf\n", res);
    return 0;
}

