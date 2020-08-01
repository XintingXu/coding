#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)(a) - *(int *)(b));
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int gBegin = 0;
    int sBegin = 0;
    int result = 0;

    while (sBegin < sSize && gBegin < gSize) {
        if (*(g + gBegin) <= *(s + sBegin)) {
            ++ result;
            ++ sBegin;
            ++ gBegin;
        } else {
            ++ sBegin;
        }
    }

    return result;
}

int main() {
    int g[3] = {1, 2, 3};
    int s[2] = {1, 1};
    printf("%d\n", findContentChildren(g, sizeof(g) / sizeof(int), s, sizeof(s) / sizeof(int)));
    return 0;
}
