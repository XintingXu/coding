#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (nums1 == NULL || nums2 == NULL || returnSize == NULL || nums1Size == 0 || nums2Size == 0) {
        *returnSize = 0;
        return NULL;
    }

    int count[1005];
    for (int i = 0 ; i < nums2Size ; ++ i) {
        count[i] = -1;
        for (int j = i + 1 ; j < nums2Size ; ++ j) {
            if (*(nums2 + j) > *(nums2 + i)) {
                count[i] = *(nums2 + j);
                break;
            }
        }
    }

    int *result = (int *)malloc(sizeof(int) * nums1Size);
    memset(result, 0, sizeof(int) * nums1Size);

    for (int i = 0 ; i < nums1Size ; ++ i) {
        for (int j = 0 ; j < nums2Size ; ++ j) {
            if (*(nums1 + i) == *(nums2 + j)) {
                *(result + i) = count[j];
                break;
            }
        }
    }

    *returnSize = nums1Size;
    return result;
}

int main() {
    return 0;
}
