#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int N;
    int M;
    int *A;
    int *B;
    int left;
    int right;
    int mid;

    scanf("%d %d", &N, &M);
    A = (int *)malloc(N * sizeof(int));
    B = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < M; i++)
        scanf("%d", &B[i]);

    qsort(A, N, sizeof(int), compare);

    for (int i = 0; i < M; i++)
    {
        left = 0;
        right = N;
        while (left != right)
        {
            mid = (left + right) / 2;
            if (A[mid] > B[i])
                right = mid;
            else
                left = mid + 1;
        }
        int res = left;
        printf("%d\n", res);
    }
}
