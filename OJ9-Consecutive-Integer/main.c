#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    if (n & (n - 1)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
