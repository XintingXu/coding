#include <stdio.h>

#define abs(n) (n >= 0 ? n : -n)
#define max(a, b) (a >= b ? a : b)

int get_steps(int x, int y, int *n)
{
    int result = 0;
    *n = max(abs(x), abs(y));

    result += *n - x;
    result += y + *n;

    if (y > -x) {
        result = 8 * (*n) - result;
    }

    return result;
}

int main()
{
    int x = 0;
    int y = 0;

    while (scanf("%d%d", &x, &y) != EOF) {
        int n = 0;
        int steps = get_steps(x, y, &n);
        steps = (2 * n + 1) * (2 * n + 1) - steps;
        printf("%d\n", steps);
    }

    return 0;
}
