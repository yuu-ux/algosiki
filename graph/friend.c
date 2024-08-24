#include <stdio.h>

int	main(void)
{
	int N;
	int A;
	int B;
	char S;
	scanf("%d", &N);
	char friend_ship[N][N];
	scanf("%d", &A);
	scanf("%d", &B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf(" %c", &S);
			friend_ship[i][j] = S;
		}
	}
	if (friend_ship[A][B] == 'o')
		printf("Yes");
	else
		printf("No");
}
