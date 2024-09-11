#include <stdio.h>
#include <stdlib.h>

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int left, int right)
{
    int pivot;
    int i;
    int j;

    i = left + 1;
    j = right;
    pivot = left;

    while (i <= j)
    {
        while (i <= right && array[i] < array[pivot])
            i++;
        while (j > left && array[pivot] < array[j])
            j--;
        if (i < j)
        {
            ft_swap(&array[i], &array[j]);
            i++;
            j--;
        }
        else if (i == j)
        {
            i++;
            j--;
        }
    }
    if (j > left)
        ft_swap(&array[pivot], &array[j]);
    return j;
}

void    quick_sort(int *array, int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(array, left, right);
        quick_sort(array, left, pivot-1);
        quick_sort(array, pivot+1, right);
    }
}

int main(void)
{
    int N;
    int *A;

    scanf("%d", &N);
    A = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    quick_sort(A, 0, N-1);
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    free(A);
    return 0;
}
