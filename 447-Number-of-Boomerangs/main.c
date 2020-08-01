#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int distance_values[500];

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    if (points == NULL) {
        return 0;
    }

    int result = 0;

    for (int point = 0 ; point < pointsSize ; ++ point) {
        int distance_count = 0;

        for (int check = 0 ; check < pointsSize ; ++ check) {
            int point_x = *(*(points + point) + 0);
            int point_y = *(*(points + point) + 1);

            int check_x = *(*(points + check) + 0);
            int check_y = *(*(points + check) + 1);

            int distance = (point_x - check_x) * (point_x - check_x) + (point_y - check_y) * (point_y - check_y);

            distance_values[distance_count] = distance;
            ++ distance_count;
        }

        qsort(distance_values, distance_count, sizeof(int), cmp);
        for (int index = 0 ; index < distance_count ;) {
            int count = 0;
            int value = distance_values[index];
            while (index < distance_count && distance_values[index] == value) {
                ++ count;
                ++ index;
            }

            result += (count - 1) * count;
        }
    }

    return result;
}


int main() {
    int input_rows = 3, input_cols = 2;
    int **points = (int **)malloc(sizeof(int *) * (unsigned int)input_rows);
    memset(points, 0, sizeof(int *) * (unsigned int)input_rows);
    for (int i = 0 ; i < input_rows ; ++i) {
        *(points + i) = (int *)malloc(sizeof(int) * (unsigned int)input_cols);
        *(*(points + i) + 0) = i + 1;
        *(*(points + i) + 1) = 0;
    }

    int *pointsColSize = 0;
    printf("%d\n", numberOfBoomerangs(points, 3, pointsColSize));

    for (int i = 0 ; i < input_rows ; ++i) {
        free(*(points + i));
        *(points + i) = NULL;
    }
    free(points);

    return 0;
}
