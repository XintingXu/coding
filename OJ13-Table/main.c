#include <stdio.h>

void printSeperator(int cols) {
    printf("|");
    for (int i = 0 ; i < cols ; ++i) {
        printf("   |");
    }
    printf("\n");
}

void printRow(int cols) {
    printf("+");
    for (int i = 0 ; i < cols ; ++i) {
        printf("---+");
    }
    printf("\n");
}

int main() {
    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    printRow(m);
    for (int row = 0 ; row < n ; ++row) {
        printSeperator(m);
        printRow(m);
    }

    return 0;
}
