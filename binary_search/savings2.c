#include <stdio.h>
#include <stdlib.h>

long long f(long long x) {
    return x * (x + 1) / 2;
}

int main(void) {
    int N;
    scanf("%d", &N);
    long long *X = (long long *)malloc(sizeof(long long) * N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &X[i]);

    for (int i = 0; i < N; i++) {
        long long left = 1;
        long long right = 2e9; // 適切な上限値
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (f(mid) >= X[i])
                right = mid;
            else
                left = mid + 1;
        }
        printf("%lld\n", left);
    }
    free(X);
    return 0;
}
