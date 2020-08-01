#include <stdio.h>
#define bool short
#define true 1
#define false 0

#define isUpper(character) (*character >= 'A' && *character <= 'Z')
#define isLower(character) (*character >= 'a' && *character <= 'z')

bool detectCapitalUse(char *word){
    if (word == NULL || *word == 0) {
        return true;
    }

    char *first = word;
    char *second = word + 1;
    char *word_temp = word + 1;

    while (*word_temp != 0) {
        if ((isUpper(second) != isUpper(word_temp)) ||
                (isLower(first) && !isLower(word_temp))) {
            return false;
        }
        ++ word_temp;
    }
    return true;
}

int main(int argc, char *argv[]) {
    return 0;
}
