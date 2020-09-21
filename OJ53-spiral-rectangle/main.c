#include <stdio.h>

int g_matrix[11][11];
int g_sum = 0;

void full_g_matrix(int n, int base_x, int base_y)
{
    if (n <= 0) {
        return;
    }
    for (int col = 0; col < n; ++col) {
        ++g_sum;
        g_matrix[base_x + col][base_y] = g_sum;
    }

    for (int row = 1; row < n - 1; ++row) {
        ++g_sum;
        g_matrix[base_x + n - 1][base_y + row] = g_sum;
    }

    for (int x = n - 1; x > 0; --x) {
        ++g_sum;
        g_matrix[base_x + x][base_y + x] = g_sum;
    }

    full_g_matrix(n - 3, base_x + 2, base_y + 1);
}

void print_g_matrix(int n)
{
    for (int row = 0; row < n; ++row) {
        for (int col = row; col < n - 1; ++col) {
            printf("%d ", g_matrix[col][row]);
        }
        printf("%d\n", g_matrix[n - 1][row]);
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    memset(g_matrix, 0, sizeof(g_matrix));
    full_g_matrix(n, 0, 0);

    print_g_matrix(n);

    return 0;
}
