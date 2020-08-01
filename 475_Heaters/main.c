#include <stdio.h>
#include <stdlib.h>

int *cmp(const void *a, const void *b) {
    return (*((int *)(a)) - *((int *)(b)));
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    if (houses == NULL || housesSize == 0 || heaters == NULL || heatersSize == 0) {
        return 0;
    }
    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);

    int result = 0;

    int current_houses = 0;
    int current_heaters = 0;
    while (current_houses < housesSize) {
        int last_r = abs(*(houses + current_houses) - *(heaters + current_heaters));
        while (current_heaters < heatersSize) {
            int current_r = abs(*(houses + current_houses) - *(heaters + current_heaters));
            if (current_r > last_r) {
                -- current_heaters;
                break;
            }
            ++ current_heaters;
            last_r = current_r;
        }

        ++ current_houses;
        if (last_r > result) {
            result = last_r;
        }
        if (current_heaters == heatersSize) {
            -- current_heaters;
        }
    }

    return result;
}

int main() {
    //int houses[6] = {2,999,5687,797987,797988,999999};
    //int heaters[3] = {1,3,6};

    int houses[25000];
    int heaters[25000];
    for (int i = 1 ; i <= 25000 ; ++ i) {
        houses[i - 1] = i +100;
        heaters[i - 1] = i;
    }


    printf("%d\n", findRadius(houses, sizeof(houses) / sizeof(int), heaters, sizeof(heaters) / sizeof(int)));
    return 0;
}
