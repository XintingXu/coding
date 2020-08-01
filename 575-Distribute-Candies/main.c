#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int distributeCandies(int *candies, int candiesSize) {
    int kinds = 0;

    qsort(candies, candiesSize, sizeof(int), cmp);

    int index = 0;
    while (index < candiesSize) {
        int index_before = index;

        while (index < candiesSize && candies[index] == candies[index_before]) {
            ++ index;
        }

        ++ kinds;
        if (kinds >= candiesSize >> 1) {
            break;
        }
    }

    return kinds;
}

int main() {
    return 0;
}
