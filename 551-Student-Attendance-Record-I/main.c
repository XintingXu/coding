#include <stdio.h>
#include <stdlib.h>

#define bool short
#define true 1
#define false 0

bool checkRecord(char *s){
    if (!s) {
        return true;
    }

    char *temp_s = s;
    int countA = 0;
    int countL = 0;
    while (*temp_s) {
        if (*temp_s == 'A') {
            ++ countA;
        }
        if (*temp_s == 'L') {
            ++ countL;
        } else {
            countL = 0;
        }

        if (countA > 1 || countL > 2) {
            return false;
        }

        ++ temp_s;
    }

    return true;
}

int main() {
    return 0;
}
