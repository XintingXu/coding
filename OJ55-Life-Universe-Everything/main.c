#include <stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 42) {
            break;
        }
        printf("%d\n", n);
    }
    return 0;
}
