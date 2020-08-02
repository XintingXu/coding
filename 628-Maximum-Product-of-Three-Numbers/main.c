#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *)b) - *((int *)a);
}

#define max(a, b) (a >= b ? a : b)

/*
最终选择的情况包括：
1. 三正数，从最大的数中选择
2. 两负一正，最大的正数和最小的两个负数
3. 两正一负，最小的两个正数和最大的负数，只有三个数时会出现
4. 三负，最大的三个数（全为负数）
*/

int maximumProduct(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);

    return max(nums[0] * nums[1] * nums[2], nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]);
}

int main() {
    int data[6] = {-4, -3, -2, -1, 2, 60};
    printf("%d\n", maximumProduct(data, sizeof(data) / sizeof(int)));
    return 0;
}
