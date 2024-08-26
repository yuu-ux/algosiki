# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int	*friend;
	int	size;
} info;

// 比較して一致したら0を返したい
int	comp_fri(int *n1, int n2, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (n1[i] == n2)
			return 0;
	}
	return 1;
}

int	main(void)
{
	int	N;
	int	M;
	int	X;
	int	n;
	int	m;
	int	res = 0;;
	int	temp = 0;
	int	cnt = 0;
	int *count = (int *)malloc(sizeof(int) * N);
	scanf("%d %d %d", &N, &M, &X);
	info	*turtle = (info *)malloc(sizeof(info) * N);

	int *friend_of_friend = (int *)malloc(sizeof(int) * N);
	// 構造体を初期化する
	for (int i = 0; i < N; i++)
	{
		turtle[i].friend = (int *)malloc(sizeof(int) * N);
		turtle[i].size = 0;
	}

	// 値を受け取る
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &n, &m);
		turtle[n].friend[turtle[n].size] = m;
		turtle[m].friend[turtle[m].size] = n;
		turtle[n].size += 1;
		turtle[m].size += 1;
	}

	// Xの友達を配列に格納する
	for (int i = 0; i < turtle[X].size; i++)
	{
		friend_of_friend[i] = turtle[X].friend[i];
		cnt++;
	}
	
	// Xの友達の友達の数をカウントする
	// 0が友達であれば弾く、1か5が友達であれば弾く
	for (int i = 0; i < turtle[X].size; i++)
	{
		temp = turtle[X].friend[i]; //0の0番目の友達つまり5がtempに入る
		for (int j = 0; j < turtle[temp].size; j++)
		{
			if (turtle[temp].friend[j] != X && comp_fri(friend_of_friend, turtle[temp].friend[j], cnt) && !(count[turtle[temp].friend[j]]))
			{
				count[turtle[temp].friend[j]] = 1;
				res += 1;
			}
		}
	}
	printf("%d\n", res);
}
