#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int *result = (int *)malloc(sizeof(int) * 2);
    memset(result, 0, sizeof(int) * 2);

    int *index = (int *)malloc(sizeof(int) * numsSize);
    memset(index, 0, sizeof(int) * numsSize);

    for (int i = 0 ; i < numsSize ; ++i) {
        ++ index[nums[i] - 1];
    }

    for (int i = 0 ; i < numsSize ; ++i) {
        if (index[i] == 2) {
            result[0] = i + 1;
        }
        if (index[i] == 0) {
            result[1] = i + 1;
        }
    }

    free(index);
    return result;
}

int main() {
    printf("Hello World!\n");
    return 0;
}
