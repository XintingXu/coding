#include <stdio.h>

void printLayer(int n, int layer)
{
    for (int i = 1; i < n - layer; ++i) {
        printf(" ");
    }
    for (int i = 0; i <= layer; ++i) {
        printf("%d", i + 1);
    }
    for (int i = layer; i >= 1; --i) {
        printf("%d", i);
    }
    printf("\n");
}

void printTower(int n)
{
    for (int layer = 0; layer < n; ++layer) {
        printLayer(n, layer);
    }
}

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        printTower(n);
    }
    return 0;
}
