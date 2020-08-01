#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

/* Direct search and compare, time complexity is O(n), storage complexity is O(1) */

/*
bool isSubsequence(char * s, char * t) {
    if (s == NULL || t == NULL) {
        return false;
    }

    while (*s != '\0' && *t != '\0') {
        while (*t != *s && *t != '\0') {
            ++ t;
        }

        if (*s == *t) {
            ++ s;
            ++ t;
        }
    }

    if (*s == '\0') {
        return true;
    } else {
        return false;
    }
}
*/


/* What if the loop size is decreased */
bool isSubsequence(char * s, char * t) {
    if (s == NULL || t == NULL) {
        return false;
    }

    while (*s != '\0' && *t != '\0') {
        if (*s == *t) {
            ++ s;
        }

        ++ t;
    }

    if (*s == '\0') {
        return true;
    } else {
        return false;
    }
}


int main() {
    char *s = "axc";
    char *t = "ahbgdc";

    printf("result is %d\n", isSubsequence(s, t));

    return 0;
}
