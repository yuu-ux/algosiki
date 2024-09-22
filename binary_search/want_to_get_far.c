#include <stdio.h>
#include <stdlib.h>

int build_towers(int min_dist, int *x, int cnt)
{
    // 塔を建てた回数を示す
    int ret = 0;
    // 最後に塔を建てた数をカウントする変数
    // 初めにめっちゃでかい値を入れることで初めの値が何で始まっても塔を建てられるようにする
    int left_pos = -1e9;//1の9乗
    for (int i = 0; i < cnt; i++)
    {
        // 今の探索位置と前回建てた塔の座標を引いて間隔をを求める
        // 間隔がmid以上であれば塔を建てられるからretをインクリメントする
        // left_posの座標を更新する
        if (x[i] - left_pos >= min_dist)
        {
            ret++;
            left_pos = x[i];
        }
    }
    return ret;
}

int main(void)
{
    int N;
    int K;
    int cnt;
    int *x;

    // 入力を受け取る
    scanf("%d %d", &N, &K);
    x = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    // leftを1でrightをxの最大値に設定して二分探索を開始する
    int left = 1;
    int right = x[N-1];
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        // mid間隔で塔を立てたらどうなるか求める
        int num_of_towers = build_towers(mid, x, N);
        // もしK以上党が立っていたらもっと感覚を開くしても大丈夫だからleftをmidに更新する
        // もしKより立てられなかったら範囲が広すぎるから狭くしてもう一回探索する
        if (num_of_towers >= K)
            left = mid;
        else
            right = mid;
    }
    printf("%d\n", left);
}
