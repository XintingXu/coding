#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int findLUSlength(char * a, char * b) {
    if (strcmp(a, b) == 0) {
        return -1;
    }

    return strlen(a) > strlen(b) ? strlen(a) : strlen(b);
}

int main() {
    return 0;
}
