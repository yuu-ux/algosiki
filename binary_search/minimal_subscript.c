#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	N;
	int	M;
	int	*A;
	int *B;
	int left;
	int right;
	int	mid;

	scanf("%d %d", &N, &M);
	
	A = (int *)malloc(sizeof(int) * N);
	B = (int *)malloc(sizeof(int) * M);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &B[i]);

	for (int i = 0; i < M; i++)
	{
		left = 0;
		right = N - 1;
		while (left != right)
		{
			mid = (left + right) / 2;
			if (A[mid] >= B[i])	
				right = mid;
			else
				left = mid + 1;
		
		}
		printf("%d\n", left);
	}
	return 0;
}

