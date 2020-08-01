#include <stdio.h>
#define min(a, b) a >= b ? b : a

int maxCount(int m, int n, int **ops, int opsSize, int *opsColSize){
    int overlapped_x = m;
    int overlapped_y = n;

    for (int operation = 0 ; operation < opsSize ; ++ operation) {
        overlapped_x = min(overlapped_x, ops[operation][0]);
        overlapped_y = min(overlapped_y, ops[operation][1]);
    }

    return overlapped_x * overlapped_y;
}

int main() {
    return 0;
}
