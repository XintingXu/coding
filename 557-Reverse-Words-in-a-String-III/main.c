#include <stdio.h>

char *reverseWords(char *s) {
    if (!s) {
        return s;
    }
    char *begin = s;
    char *end = begin;

    while (*end) {
        while (*end && *end != ' ') {
            ++ end;
        }
        char *temp_end = end - 1;
        while (begin < temp_end) {
            char temp = *begin;
            *begin = *temp_end;
            *temp_end = temp;

            ++ begin;
            -- temp_end;
        }

        if (*end) {
            ++ end;
        }
        begin = end;
    }

    return s;
}

int main() {
    return 0;
}
