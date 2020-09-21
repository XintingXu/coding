#include <stdio.h>

int max_common_divisor(int a, int b)
{
    int min = a >= b ? b : a;
    while (a % min != 0 || b % min != 0) {
        --min;
    }
    return min;
}

int judgeWinner(int a, int b, int n)
{
    if (n == 0) {
        return 1;
    }
    n -= max_common_divisor(a, n);
    if (n == 0) {
        return 0;
    }
    n -= max_common_divisor(b, n);

    return judgeWinner(a, b, n);
}

int main()
{
    int a = 0;
    int b = 0;
    int n = 0;

    while (scanf("%d%d%d", &a, &b, &n) != EOF) {
        printf("%d\n", judgeWinner(a, b, n));
    }
    return 0;
}
