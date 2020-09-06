#include <stdio.h>
#include <stdlib.h>

int g_results[130][130];

void get_solutions()
{
    for (int x = 1; x <= 125; ++x) {
        for (int y = 1; y <= x; ++y) {
            if (x == 1 || y == 1) {
                g_results[x][y] = 1;
                continue;
            }

            if (x == y) {
                g_results[x][y] = 1 + g_results[x][y - 1];
                continue;
            }

            if (x - y > y) {
                g_results[x][y] = g_results[x][y - 1] + g_results[x - y][y];
                continue;
            }

            g_results[x][y] = g_results[x][y - 1] + g_results[x - y][x - y];
        }
    }
}

int main()
{
    unsigned int N = 0;
    memset(g_results, 0, sizeof(g_results));
    get_solutions();

    while (scanf("%d", &N) != EOF) {
        printf("%d\n", g_results[N][N]);
    }
    return 0;
}
