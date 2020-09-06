#include <stdio.h>

int isAlphabet(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return  c - 'Z' + 'a';
    }
    return c;
}

char toUpper(char c)
{
    if (c >= 'a' && c <= 'z') {
        return  c - 'a' + 'A';
    }
    return c;
}

int main()
{
    int word_count = 0;
    int alpha_count = 0;
    char s = 0;
    while (scanf("%c", &s) && s != '\n') {
        if (isAlphabet(s)) {
            if (word_count != 0 && alpha_count == 0) {
                printf(" ");
            }

            if (alpha_count == 0) {
                printf("%c", toUpper(s));
                ++word_count;
            } else {
                printf("%c", toLower(s));
            }

            ++alpha_count;
        } else {
            alpha_count = 0;
        }
    }

    printf(".\n");

    return 0;
}
