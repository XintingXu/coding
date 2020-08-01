#include <stdio.h>
#include <stdlib.h>

int minMoves(int* nums, int numsSize) {
    int result = 0;
    int min = *(nums);

    for (int i = 0 ; i < numsSize ; ++ i) {
        result += *(nums + i) - *(nums);

        if (*(nums + i) < min) {
            min = *(nums + i);
        }
    }

    result += (*nums - min) * (numsSize);
    return result;
}

int main() {
    int nums[4] = {9,7,1,12};
    int result = minMoves(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", result);
    return 0;
}
