#include <stdio.h>

int hammingDistance(int x, int y){
    int differ = 0;
    while (x || y) {
        if ((x & 1) != (y & 1)) {
            ++ differ;
        }
        x = x >> 1;
        y = y >> 1;
    }
    return differ;
}

int main() {
    printf("Hello World!\n");
    return 0;
}
