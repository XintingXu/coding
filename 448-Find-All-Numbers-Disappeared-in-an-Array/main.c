#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){

    for (int i = 0 ; i < numsSize ; ++ i) {
        int index = *(nums + i);
        if (*(nums + i) < 0) {
            index *= -1;
        }
        -- index;
        if (*(nums + index) > 0) {
            *(nums + index) *= -1;
        }
    }
    /*数组原地判断，虽然空间利用率高，但性能较差*/

    int disappred_count = 0;
    for (int i = 0 ; i < numsSize ; ++ i) {
        if (*(nums + i) > 0) {
            ++ disappred_count;
        }
    }

    int *result = (int *)malloc(sizeof(int) * disappred_count);
    //memset(result, 0, sizeof(int) * disappred_count);
    for (int i = 0, current = 0 ; i < numsSize ; ++ i) {
        if (*(nums + i) > 0) {
            *(result + current) = 1 + i;
            ++ current;
        }
    }

    *returnSize = disappred_count;
    return result;
}


int main()
{
    int nums[8] = {4,4,4,4,4,4,4,4};
    int returnSize;
    int *result = findDisappearedNumbers(nums, 8, &returnSize);

    for (int i = 0 ; i < returnSize ; ++ i) {
        printf("%d, ", *(result + i));
    }

    if (result != NULL) {
        free(result);
    }
    return 0;
}
