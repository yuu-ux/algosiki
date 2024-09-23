#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    printf("%d\n", (N / 5 + N % 5));
}
//int main(void)
//{
//    int N;
//    int cnt;
//    scanf("%d", &N);
//    cnt = 0;
//    while (N != 0)
//    {
//        if (N - 5 >= 0)
//        {
//            N -= 5;
//            cnt++;
//        } else {
//            N -= 1;
//            cnt++;
//        }
//    }
//    printf("%d\n", cnt);
//}

