#include <stdio.h>

int isFirst = 1;

void get_diviser(int n)
{
    if (n == 1) {
        return;
    }
    if (!isFirst) {
        printf("*");
    } else {
        isFirst = 0;
    }

    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            printf("%d", i);
            n /= i;
            break;
        }
    }

    get_diviser(n);
}

int main()
{
    int n = 0;

    while(scanf("%d", &n) != EOF) {
        isFirst = 1;
        get_diviser(n);
        printf("=%d\n", n);
    }
    return 0;
}
