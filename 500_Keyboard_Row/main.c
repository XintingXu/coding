#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize) {
    int rowsMark[3] = {22790416, 265961, 44052486};

    char **result = NULL;
    int *verifiedIndexs = (int *)malloc(sizeof(int) * wordsSize);
    int verifiedCount = 0;
    memset(verifiedIndexs, 0, sizeof(int) * wordsSize);

    for (int index = 0 ; index < wordsSize ; ++ index) {
        char *word = *(words + index);
        int row = *word >= 'a' && *word <= 'z' ? *word - 'a' : *word - 'A';
        row = 1 << row;
        if (row & rowsMark[0]) {
            row = 0;
        } else if (row & rowsMark[1]) {
            row = 1;
        } else {
            row = 2;
        }

        while (*word != 0) {
            int character = *word >= 'a' && *word <= 'z' ? *word - 'a' : *word - 'A';
            character = 1 << character;
            if (!(character & rowsMark[row])) {
                break;
            }
            ++ word;
        }

        if (*word == 0) {
            *(verifiedIndexs + verifiedCount) = index;
            ++ verifiedCount;
        }
    }

    result = (char **)malloc(sizeof(char *) * verifiedCount);
    for (int i = 0 ; i < verifiedCount ; ++ i) {
        char *src = *(words + *(verifiedIndexs + i));
        *(result + i) = (char *)malloc(strlen(src) + 1);
        char *dst = *(result + i);
        strcpy(dst, src);
        //printf("src = %s, dst = %s\n", src, dst);
    }

    free(verifiedIndexs);
    verifiedIndexs = NULL;

    *returnSize = verifiedCount;
    return result;
}

int main() {
    int sourceSize = 3;
    char **words = (char **)malloc(sizeof(char *) * sourceSize);
    *words = (char *)malloc(sizeof(char) * (strlen("Hello") + 1));
    strcpy(*words, "Hello");
    *(words + 1) = (char *)malloc(sizeof(char) * (strlen("AsdfG") + 1));
    strcpy(*(words + 1), "AsdfG");
    *(words + 2) = (char *)malloc(sizeof(char) * (strlen("World") + 1));
    strcpy(*(words + 2), "World");

    int resultSize = 0;
    char **result = findWords(words, sourceSize, &resultSize);
    for (int i = 0 ; i < resultSize ; ++ i) {
        printf("%s\n", *(result + i));
        free(*(result + i));
        *(result + i) = NULL;
    }
    free(result);

    for (int i = 0 ; i < sourceSize ; ++ i) {
        free (*(words + i));
        *(words + i) = NULL;
    }
    free(words);

    return 0;
}
