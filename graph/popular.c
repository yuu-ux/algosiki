#include <stdio.h>
#include <stdlib.h>

typedef struct fri{
	int *friend;
	int size;
} fri;

// 友達が最も多い亀の添字を返す
int	ft_max_friend(fri *people, int N)
{
	int res;
	
	res = 0;
	for (int i = 1; i < N; i++)
	{
		if (people[res].size < people[i].size)
			res = i;
	}
	return (res);
}

void	ft_sort(int *people, int n)
{
	int temp;

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (people[i] > people[j])
			{
				temp = people[i];
				people[i] = people[j];
				people[j] = temp;
			}
		}
	}
}

int	main(void)
{
	int	N;
	int	M;
	int	n;
	int	m;
	int	max;
	scanf("%d %d", &N, &M);
	fri	people[N];
	
	// people配列を初期化する
	for (int i = 0; i < N; i++)
	{
		people[i].friend = (int *)malloc(sizeof(int) * (N-1));
		people[i].size = 0;
	}
	
	// 入力値を受け取る
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &n);
		scanf("%d", &m);
		people[n].friend[people[n].size] = m;
		people[m].friend[people[m].size] = n;
		people[n].size += 1;
		people[m].size += 1;
	}

	// 友達が最も多い亀を特定する
	max = ft_max_friend(people, N);
	
	// 最も友達が多い亀の友達を昇順にする
	ft_sort(people[max].friend, people[max].size);

	// 最も友達が多い亀の友達を表示する
	for (int i = 0; i < people[max].size; i++)
	{
		printf("%d ", people[max].friend[i]);
	}
	printf("\n");
}
