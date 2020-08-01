#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool short
#define true 1
#define false 0

bool repeatedSubstringPattern(char *s){
    if (s == NULL) {
        return false;
    }
    bool result = false;

    int s_len = strlen(s);
    char *s_s = (char *)malloc(sizeof(char) * s_len * 2 - 2);

    memcpy_s(s_s, s_len * 2 - 2, s + 1, s_len - 1);
    memcpy_s(s_s + s_len - 1, s_len - 1, s, s_len - 1);

    for (int index = 0 ; index <= s_len - 2 ; ++ index) {
        if (*s == *(s_s + index) && memcmp(s, s_s + index, s_len) == 0) {
            result = true;
            break;
        }
    }

    free(s_s);
    return result;
}

int main() {
    char *s = "aa";
    printf("%d\n", repeatedSubstringPattern(s));
    return 0;
}
