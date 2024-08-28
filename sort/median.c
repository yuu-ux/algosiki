#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
		return *(int*)a - *(int*)b;
}

int	main(void)
{
		int	N;
		int	i;
		int	*array;
		int	j;
		double	temp;
		double	res;

		i = 0;
		scanf("%d", &N);
		array = (int *)malloc(sizeof(int) * N);

		// 入力を受け取る
		while (i < N)
		{
				scanf("%d", &array[i]);
				i++;
		}

		// ソートする
		qsort(array, N, sizeof(int), compare);

		// 中央値を求める
		if (N % 2 == 1)
				res = array[N / 2];
		else
		{
				temp = array[N / 2 - 1];
				res = (temp + array[N / 2]) / 2;
		}
		printf("%.1f\n", res);
}
