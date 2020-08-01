#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **matrixReshape(int **nums, int numsSize, int *numsColSize, int r, int c,
                    int *returnSize, int **returnColumnSizes) {
    if (!nums || !numsSize || numsSize * (*numsColSize) != r * c) {
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }

    int **result = (int **)malloc(sizeof(int *) * r);
    *returnColumnSizes = (int *)malloc(sizeof(int) * r);
    for (int row = 0 ; row < r ; ++ row) {
        result[row] = (int *)malloc(sizeof(int) * c);
        (*returnColumnSizes)[row] = c;
    }

    for (int index = 0 ; index < r * c ; ++ index) {
        result[index / c][index % c] = nums[index / *numsColSize][index % *numsColSize];
    }

    *returnSize = r;
    return result;
}

int main() {
    return 0;
}
