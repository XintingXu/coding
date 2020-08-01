#include <stdio.h>

char *reverseStr(char *s, int k){
    if (s == NULL || k <= 1) {
        return s;
    }

    int periods = 0;
    int begin = 0;
    int end = 0;

    while (*(s + end)) {
        ++ periods;
        begin = end;
        while (*(s + end) && end - begin < k) {
            ++ end;
        }

        if (periods % 2) {
            char *start = s + begin;
            char *finish = s + end - 1;

            while (start < finish) {
                *start ^= *finish;
                *finish ^= *start;
                *start ^= *finish;

                ++ start;
                -- finish;
            }
        }
    }

    return s;
}

int main() {
    return 0;
}
