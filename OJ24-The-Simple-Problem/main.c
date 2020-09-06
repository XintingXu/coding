#include <stdio.h>

int main()
{
    int a = 0;
    int k = 0;
    int n = 0;

    scanf("%d%d%d", &a, &k, &n);

    printf("%d\n", a * (n + 1) + (n * k * (1 + n)) / 2);
    return 0;
}
