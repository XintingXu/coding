#include <stdio.h>

long long getCount(int n, int m, int a)
{
    n = n % a == 0 ? n / a : n / a + 1;
    m = m % a == 0 ? m / a : m / a + 1;

    return (long long)n * (long long)m;
}

int main()
{
    int n = 0;
    int m = 0;
    int a = 0;

    while (scanf("%d%d%d", &n, &m, &a) != EOF) {
        printf("%lld\n", getCount(n, m, a));
    }

    return 0;
}
