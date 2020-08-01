#include <stdio.h>


/* Compress the char string */
int compress(char* chars, int charsSize) {
    int resultSize = charsSize < 2 ? charsSize : 0;

    char last_c = *chars;
    int last_count = 1;
    for (int i = 1 ; i < charsSize ; ++ i) {
        while (i < charsSize && *(chars + i) == last_c) {
            ++ last_count;
            ++ i;
        }

        *(chars + resultSize) = last_c;
        ++ resultSize;
        if (last_count > 1) {
            char integers[8];
            sprintf(integers, "%d", last_count);
            int integer_length = strlen(integers);
            memcpy(chars + resultSize, integers, integer_length);
            resultSize += integer_length;
        }

        if (i < charsSize) {
            last_c = *(chars + i);
            last_count = 1;
        }
    }

    return resultSize;
}


int main() {
    char test[14] = "abbbbbbbbbbccc";
    compress(test, 14);
    printf("%s\n", test);
    return 0;
}
