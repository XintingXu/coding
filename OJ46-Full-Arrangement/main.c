#include <stdio.h>

void printArrange(int *arrange, int n)
{
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", arrange[i]);
    }
    printf("%d\n", arrange[n - 1]);
}

void arrangeFunc(int *isChoosen, int *arrange, int n, int choosenCount)
{
    if (choosenCount == n) {
        printArrange(arrange, n);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!isChoosen[i]) {
            arrange[choosenCount] = i + 1;
            isChoosen[i] = 1;
            arrangeFunc(isChoosen, arrange, n, choosenCount + 1);
            isChoosen[i] = 0;
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int isChoosen[10];
    int arrange[10];
    memset(isChoosen, 0, sizeof(isChoosen));
    memset(arrange, 0, sizeof(arrange));

    arrangeFunc(isChoosen, arrange, n, 0);

    return 0;
}
