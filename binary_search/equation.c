#include <stdio.h>

double binary_search(double X, int N)
{
    if ((X(X(X + 1) + 2) + 3) > N)
        return X;
    binary_search(X+0.01, N);
}

int main(void) {
    int N;
    double res;

    res = 0.01;
    scanf("%d", &N);
    res = binary_search(res, N);
  printf("%f\n", res);
  return 0;
}
