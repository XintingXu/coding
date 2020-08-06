#include <stdio.h>

int main() {
    int n = 0;
    int count = 0;

    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++i) {
        if (n % i == 0) {
            ++ count;
        }
    }

    printf("%d", count);
    for (int i = 1 ; i <= n ; ++i) {
        if (n % i == 0) {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}
