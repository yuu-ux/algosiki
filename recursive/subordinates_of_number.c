#include <stdio.h>
#include <stdlib.h>

int is_staff(int X, int **staffs, int *staff_count)
{
    int result;
    int staff;

    result = 0;
    for (int i = 0; i < staff_count[X]; i++)
    {
        staff = staffs[X][i];
        result += is_staff(staff, staffs, staff_count) + 1;
    }
    return result;
}

int main(void)
{
    int N;
    int X;
    int *P;
    int **staffs;
    int *staff_count;
    int manager;

    scanf("%d %d", &N, &X);
    P = (int *)malloc(sizeof(int) * N);

    // 入力を受け取る
    for (int i = 1; i < N; i++)
        scanf("%d", &P[i]);

    // 部下を格納する
    staffs = (int **)malloc(sizeof(int *) * N);
    // 部下の人数を数える
    staff_count = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
        staffs[i] = (int *)malloc(sizeof(int) * N);
    // マネージャーと部下の2次元配列を作る
    // それと同時に各マネージャーに何人部下がいるのかをカウントする
    for (int i = 1; i < N; i++)
    {
        manager = P[i];
        staffs[manager][staff_count[manager]++] = i;
    }

    printf("%d\n", is_staff(X, staffs, staff_count));
    for (int i = 0; i < N; i++)
        free(staffs[i]);
    free(staffs);
    free(staff_count);
    free(P);

    return 0;
}
