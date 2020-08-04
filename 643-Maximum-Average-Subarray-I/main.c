#include <stdio.h>
#include <stdlib.h>

double findMaxAverage(int* nums, int numsSize, int k){
    int result = -10010 * k;
    int result_k = 0;

    for (int i = 0 ; i < k ; ++i) {
        result_k += nums[i];
    }

    for (int i = k ; i < numsSize ; ++i) {
        if (result_k > result) {
            result = result_k;
        }

        result_k -= nums[i - k];
        result_k += nums[i];
    }

    if (result_k > result) {
        result = result_k;
    }

    return (double)result / (double)k;
}

int main() {
    printf("Hello World!\n");
    return 0;
}
