#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int findUnsortedSubarray(int *nums, int numsSize){
    if (!nums || !numsSize || numsSize == 1) {
        return 0;
    }

    int *sorted = (int *)malloc(sizeof(int) * numsSize);
    memcpy(sorted, nums, sizeof(int) * numsSize);
    qsort(sorted, numsSize, sizeof(int), cmp);

    int result = 0;
    int begin_index = 0;
    while (begin_index < numsSize && *(nums + begin_index) == *(sorted + begin_index)) {
        ++ result;
        ++ begin_index;
    }
    for (int end_index = numsSize - 1 ;
         end_index > begin_index && *(nums + end_index) == *(sorted + end_index) ;
         -- end_index) {
        ++ result;
    }

    free(sorted);

    return numsSize - result;
}

int main() {
    int nums[3] = {5, 9, 7};
    printf("%d\n", findUnsortedSubarray(nums, 3));
    return 0;
}
