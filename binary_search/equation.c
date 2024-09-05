#include <stdio.h>
#define Tolerance 0.01

double  f(double X)
{
    return X * (X * (X + 1) + 2) + 3;
}

int main(void)
{
    double N;
    scanf("%lf", &N);
    double left;
    double right;
    double mid;

    right = 100;
    left = 0;
    while ((right - left) > Tolerance)
    {
        mid = (left + right) / 2;
        if (f(mid) < N)
            left = mid;
        else
            right = mid;
    }
    printf("%lf\n", right);
    return 0;
}
