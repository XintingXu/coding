#include <stdio.h>

int getOne(int n)
{
    int result = 0;
    while (n != 0) {
        if (n & 1) {
            ++result;
        }
        n = n >> 1;
    }
    return result;
}

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", getOne(n));
    }
    return 0;
}
