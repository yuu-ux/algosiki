#include <stdio.h>

int main(void)
{
    int N;
    int i;
    scanf("%d", &N);

    i = 1;
    while (i <= N)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            printf("FizzBuzz\n");
        else if (i % 5 == 0)
            printf("Buzz\n");
        else if (i % 3 == 0)
            printf("Fizz\n");
        else
            printf("%d\n", i);
        i++;
    }
}
