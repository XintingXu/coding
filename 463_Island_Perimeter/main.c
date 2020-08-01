#include <stdio.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridColSize == NULL || gridSize == 0) {
        return 0;
    }
    int result = 0;
    int inside = 0;

    for (int row = 0 ; row < gridSize ; ++ row) {
        for (int col = 0 ; col < *(gridColSize + row) ; ++ col) {
            if (*(*(grid + row) + col) == 1) {
                ++ result;

                if (col < *(gridColSize + row) - 1 && *(*(grid + row) + col + 1) == 1) {
                    ++ inside;
                }
                if (row < gridSize - 1 && *(*(grid + row + 1) + col) == 1) {
                    ++ inside;
                }
            }
        }
    }

    result = result * 4 - inside * 2;

    return result;
}

int main() {
    printf("Hello World!\n");
    return 0;
}
