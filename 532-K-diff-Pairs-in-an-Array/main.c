#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*((int *)(a)) - *((int *)(b)));
}

int findPairs(int *nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);

    int begin = 0;
    int end = 0;
    int result = 0;

    while (begin <= end && end < numsSize) {
        if (begin == end) {
            ++ end;
        }

        while (end < numsSize && *(nums + end) - *(nums + begin) < k) {
            ++ end;
        }

        if (end < numsSize && *(nums + end) - *(nums + begin) == k) {
            ++ result;
        }
        while (end < numsSize && *(nums + end) - *(nums + begin) == k) {
            ++ end;
        }

        while (begin < end && end < numsSize &&
               *(nums + end) - *(nums + begin) > k) {
            ++ begin;
        }
    }

    return result;
}

int main() {
    int nums[5] = {3, 1, 4, 1, 4};
    printf("%d\n", findPairs(nums, 5, 1));
    return 0;
}
