#include <stdio.h>

int g_w[110];

int check(int S)
{
    if (S < 0) {
        return 0;
    }
    if (S == 0 || g_w[S]) {
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < sizeof(g_w) / sizeof(g_w[1]) && !ret; ++i) {
        if (g_w[i] == 0) {
            continue;
        }

        for (int count = 1; count <= g_w[i]; ++count) {
            g_w[i] -= count;
            ret |= check(S - i * count);
            g_w[i] += count;
        }
    }

    return ret;
}

int main()
{
    int N = 0;
    int S = 0;
    memset(g_w, 0, sizeof(g_w));

    scanf("%d%d", &N, &S);
    for (int i = 0; i < N; ++i) {
        int temp = 0;
        scanf("%d", &temp);
        ++g_w[temp];
    }

    if (check(S)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
