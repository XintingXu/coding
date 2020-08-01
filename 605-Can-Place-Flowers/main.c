#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool short
#define true 1
#define false 0

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {
    int index = 0;
    int result = 0;

    int *tempFlowerBed = (int *)malloc(sizeof(int) * (flowerbedSize + 2));
    memcpy(tempFlowerBed + 1, flowerbed, sizeof(int) * flowerbedSize);
    tempFlowerBed[0] = 0;
    tempFlowerBed[flowerbedSize + 1] = 0;
    int tempFlowerBedSize = flowerbedSize + 2;

    while (index < tempFlowerBedSize) {
        while (index < tempFlowerBedSize && tempFlowerBed[index] == 1) {
            ++ index;
        }

        int countZero = 0;
        while (index < tempFlowerBedSize && tempFlowerBed[index] == 0) {
            ++ countZero;
            ++ index;
        }

        result += countZero >= 3 ? (countZero - 3) / 2 + 1 : 0;
        if (result >= n) {
            break;
        }
    }

    free(tempFlowerBed);

    return result >= n;
}

int main() {
    int test[5] = {1, 0, 0, 0, 1};
    canPlaceFlowers(test, 5, 1);
    return 0;
}
