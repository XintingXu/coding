#include <stdio.h>

int getCount(int M, int N)
{
    return (M * N / 2);
}

int main()
{
    int N = 0;
    int M = 0;
    while (scanf("%d%d", &M, &N) != EOF) {
        printf("%d\n", getCount(M, N));
    }
    return 0;
}
