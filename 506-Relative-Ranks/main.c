#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int score;
    int index;
    int rank;
} athlete_t;

int cmp(const void *a, const void *b) {
    return (((athlete_t *)(b))->score - ((athlete_t *)(a))->score);
}

char **findRelativeRanks(int *nums, int numsSize, int *returnSize) {
    athlete_t *athletes = (athlete_t *)malloc(sizeof(athlete_t) * numsSize);
    for (int i = 0 ; i < numsSize ; ++ i) {
        (athletes + i)->score = *(nums + i);
        (athletes + i)->index = i;
    }
    qsort(athletes, numsSize, sizeof(athlete_t), cmp);

    for (int i = 0 ; i < numsSize ; ++ i) {
        (athletes + i)->rank = i + 1;
    }

    char **result = (char **)malloc(sizeof(char *) * numsSize);
    for (int i = 0 ; i < numsSize ; ++ i) {
        athlete_t *current = athletes + i;
        if (current->rank <= 3) {
            switch (current->rank) {
                case 0 : break;
                case 1 :
                    *(result + current->index) = (char *)malloc(sizeof(char) * 11);
                    sprintf(*(result + current->index), "%s", "Gold Medal");
                    break;
                case 2 :
                    *(result + current->index) = (char *)malloc(sizeof(char) * 13);
                    sprintf(*(result + current->index), "%s", "Silver Medal");
                    break;
                case 3 :
                    *(result + current->index) = (char *)malloc(sizeof(char) * 13);
                    sprintf(*(result + current->index), "%s", "Bronze Medal");
                    break;
            }
        } else {
            *(result + current->index) = (char *)malloc(sizeof(char) * 5);
            sprintf(*(result + current->index), "%d", current->rank);
        }
    }

    *returnSize = numsSize;
    return result;
}

int main() {
    return 0;
}
