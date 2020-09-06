#include <stdio.h>

int g_matrix[110][110];

#define max(a, b) (a >= b ? a : b)

int get_max(int x, int y)
{
    int dp[110][110];
    memset(dp, 0, sizeof(dp));

    for (int row = 1; row <= x; ++row) {
        for (int col = 1; col <= y; ++col) {
            dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]) + g_matrix[row][col];
        }
    }

    return dp[x][y];
}

int main()
{
    int n = 0;
    int m = 0;
    memset(g_matrix, 0, sizeof(g_matrix));

    scanf("%d%d", &n, &m);
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            scanf("%d", &g_matrix[x][y]);
        }
    }

    printf("%d\n", get_max(n, m));
    return 0;
}
