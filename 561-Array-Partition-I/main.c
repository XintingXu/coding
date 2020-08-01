#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int arrayPairSum(int *nums, int numsSize){
    if (!nums || !numsSize) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    int result = 0;
    for (int i = 0 ; i < numsSize ; i += 2) {
        result += *(nums + i);
    }

    return result;
}

int main() {
    return 0;
}
