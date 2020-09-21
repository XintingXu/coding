#include <stdio.h>

void printResult(int *isChoosen, int n)
{
    for (int index = 0; index < n; ++index) {
        if (isChoosen[index]) {
            printf("%d ", index + 1);
        }
    }
    printf("\n");
}

void dfs_search(int *isChoosen, int m, int n, int choosen)
{
    if (m == choosen) {
        printResult(isChoosen, n);
        return;
    }

    int begin = n - 1;
    while (begin > 0 && !isChoosen[begin]) {
        --begin;
    }

    for (; begin < n; ++begin) {
        if (!isChoosen[begin]) {
            isChoosen[begin] = 1;
            dfs_search(isChoosen, m, n, choosen + 1);
            isChoosen[begin] = 0;
        }
    }
}

int main()
{
    int n = 0;
    int m = 0;
    while (scanf("%d%d", &n, &m) != EOF) {
        int isChoosen[10];
        memset(isChoosen, 0, sizeof(isChoosen));
        dfs_search(isChoosen, m, n, 0);
    }
    return 0;
}
