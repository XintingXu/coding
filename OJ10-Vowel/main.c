#include <stdio.h>

int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }

    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }

    return 0;
}

void toUpper(char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c += 'A' - 'a';
    }
}

void toLower(char *c) {
    if (*c >= 'A' && *c <= 'Z') {
        *c += 'a' - 'A';
    }
}

int main() {
    char str[105];
    gets_s(str, sizeof(str));

    for (int i = 0 ; str[i] != 0 ; ++i) {
        if (isVowel(str[i])) {
            toUpper(&str[i]);
        } else {
            toLower(&str[i]);
        }
    }

    printf("%s\n", str);
    return 0;
}
