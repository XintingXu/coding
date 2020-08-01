#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Note: The returned array must be malloced, assume caller calls free(). */
char **findRestaurant(char **list1, int list1Size, char **list2, int list2Size, int *returnSize){
    char **result = (char **)malloc(sizeof(char *) * (list1Size + list2Size));

    *returnSize = 0;
    int resultSum = 0;

    for (resultSum = 2 ; resultSum <= list1Size + list2Size ; ++ resultSum) {
        for (int index = 0 ; index < list1Size ; ++ index) {
            int supIndex = resultSum - 2 - index;
            if (supIndex >= 0 && supIndex < list2Size && strcmp(list1[index], list2[supIndex]) == 0) {
                result[*returnSize] = (char *)malloc(strlen(list1[index]) + 1);
                strcpy(result[*returnSize], list1[index]);
                ++ *returnSize;
            }
        }

        if (*returnSize) {
            break;
        }
    }

    return result;
}

int main() {
    return 0;
}
