#include <stdio.h>

char mask[12500010];

int main()
{
    int n = 0;
    scanf("%d", &n);
    int result = 0;

    memset(mask, 0, sizeof(mask));

    for (int i = 2; i * i <= n; ++i) {
        for (int j = 2; i * j <= n; ++j) {
            mask[(i * j) / 8] |= 1 << (i * j) % 8;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (!(mask[i / 8] & 1 << i % 8)) {
            ++result;
        }
    }

    printf("%d\n", result);

    return 0;
}
