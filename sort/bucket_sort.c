#include <stdio.h>

void bucket_sort(int A[], int size)
{
	int num[size+1]; //要素の出現回数をカウント
	int acc[size+1]; //要素の入る位置を決定する
	int res[size]; //最終的な配列
	int i = 0;
    
    if (size == 1)
        return ;
	//numとaccを初期化する	
	for (int j = 0; j < size+1; j++)
	{
		num[j] = 0;
		acc[j] = 0;
	}
	//要素の出現回数をカウントする
	while (i < size)
	{
		num[A[i]] += 1;
		i++;
	}
	//要素の入る位置を決定する
	acc[0] = num[0];
	i = 1;
	while (i <= size)
	{
		acc[i] = acc[i-1] + num[i];
		i++;
	}
	//ソートを実行する
	//Aを後ろから入れていく
	//同様の値が存在する場合は後ろから順番に入れていく。そうすることで元の順序を守ってソートができる。
	i = size-1;
	while (i >= 0)
	{
        int temp = A[i];

		res[--acc[temp]] = temp;//累積はの-1を添字として該当する箇所に要素を入れる
		i--;
	}
	i = 0;
	while (i < size)
	{
		A[i] = res[i];
		i++;
	}
}

int main(void)
{
    int total;
    scanf("%d", &total);
    int A[total]; //配列を受け取る
    int i;
    for (i = 0; i < total; i++)
    {
        scanf("%d", &A[i]);
    }
    bucket_sort(A, total);
    for (i = 0; i < total; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
