#include <stdio.h>

int findMaxConsecutiveOnes(int *nums, int numsSize){
    int result = 0;
    int current_result = 0;
    for (int i = 0 ; i < numsSize ; ++ i) {
        if (*(nums + i) == 1) {
            ++ current_result;
        } else {
            if (current_result > result) {
                result = current_result;
            }
            current_result = 0;
        }
    }
    if (current_result > result) {
        result = current_result;
    }
    return result;
}

int main() {
    return 0;
}
