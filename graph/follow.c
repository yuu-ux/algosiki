#include <stdio.h>
#include <stdlib.h>

// 構造体定義
typedef struct list {
	int size;
	int *follow;
} list;

// 比較関数
int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

int main(void) {
	int member;
	int follow;
	
	// メンバー数とフォロー数の入力
	scanf("%d", &member);
	scanf("%d", &follow);

	// メンバー用のリストを動的に確保
	list follow_list[member];
	
	// 各メンバーの構造体を初期化
	for (int i = 0; i < member; i++) {
		follow_list[i].size = 0;
		follow_list[i].follow = (int*)malloc(follow * sizeof(int)); // フォローする最大数を確保
	}

	int m, f;
	for (int j = 0; j < follow; j++) {
		// フォロー関係の入力
		scanf("%d %d", &m, &f);
		follow_list[m].follow[follow_list[m].size] = f;
		follow_list[m].size += 1;
	}

	// 各メンバーのフォローリストを昇順にソート
	for (int i = 0; i < member; i++) {
		qsort(follow_list[i].follow, follow_list[i].size, sizeof(int), compare);
	}

	// 結果の出力
	for (int m = 0; m < member; m++) {
		for (int j = 0; j < follow_list[m].size; j++) {
			printf("%d ", follow_list[m].follow[j]);
		}
		printf("\n");
	}

	// メモリの解放
	for (int i = 0; i < member; i++) {
		free(follow_list[i].follow);
	}

	return 0;
}
