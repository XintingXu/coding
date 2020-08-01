#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

/*
int findLHS(int *nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);

    int result = 0;
    for (int i = 0 ; i < numsSize - 1 ; ++ i) {
        if (nums[i + 1] == nums[i] + 1) {
            int temp_result = 0;

            for (int left = i ; left >= 0 && nums[left] == nums[i] ; -- left) {
                ++ temp_result;
            }
            for (int right = i + 1 ; right < numsSize && nums[right] == nums[i + 1] ; ++ right) {
                ++ temp_result;
            }

            result = temp_result > result ? temp_result : result;
        }
    }

    return result;
}
*/

int findLHS(int *nums, int numsSize){
    if (!nums || !numsSize) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    int result = 0;

    int pre_value_begin = 0;
    int index = 1;
    while (index < numsSize && nums[index] == nums[pre_value_begin]) {
        ++ index;
    }

    while (index < numsSize) {
        if (nums[index] == nums[pre_value_begin] + 1) {
            int index_end = index + 1;
            while (index_end < numsSize && nums[index_end] == nums[index]) {
                ++ index_end;
            }
            if (index_end - pre_value_begin > result) {
                result = index_end - pre_value_begin;
            }

            pre_value_begin = index;
            index = index_end;
            continue;
        }

        pre_value_begin = index;
        while (index < numsSize && nums[index] == nums[pre_value_begin]) {
            ++ index;
        }
    }

    return result;
}

int main() {
    int nums[9] = {-1, 1, 1, 2, 2, 2, 2, 5, 5};
    printf("%d\n", findLHS(nums, 9));
    return 0;
}
