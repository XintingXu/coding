#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *constructRectangle(int area, int *returnSize) {
    int *result = (int *)malloc(sizeof(int) *2);
    *returnSize = 2;

    int l_sqrt = pow(area, 0.5);
    if (l_sqrt * l_sqrt == area) {
        *(result) = l_sqrt;
        *(result + 1) = l_sqrt;
        return result;
    }

    while (area % l_sqrt != 0) {
        -- l_sqrt;
    }
    *(result) = area / l_sqrt;
    *(result + 1) = l_sqrt;
    return result;
}

int main() {
    return 0;
}
