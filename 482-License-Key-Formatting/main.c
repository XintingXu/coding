#include <stdio.h>
#include <stdlib.h>

char *licenseKeyFormatting(char *S, int K) {
    int character_count = 0;
    char *S_temp = S;
    while (*S_temp != '\0') {
        if (*S_temp != '-') {
            ++ character_count;
        }
        ++ S_temp;
    }

    int ahead = character_count % K;
    int final_length = character_count + character_count / K;

    char *result = (char *)malloc(sizeof(char) * final_length + 1);
    memset(result, 0, sizeof(char) * final_length + 1);
    int index = 0;

    while (ahead) {
        if (*S != '-') {
            -- ahead;
            if (*S >= 'a' && *S <= 'z') {
                *(result + index) = *S - 'a' + 'A';
            } else {
                *(result + index) = *S;
            }
            ++ index;
        }
        ++ S;
    }

    while (*S != '\0') {
        if (*S != '-') {
            if (ahead == 0 && index) {
                *(result + index) = '-';
                ++ index;
            }

            ++ ahead;
            if (*S >= 'a' && *S <= 'z') {
                *(result + index) = *S - 'a' + 'A';
            } else {
                *(result + index) = *S;
            }
            ++ index;
        }
        ++ S;

        if (ahead == K) {
            ahead = 0;
        }
    }
    *(result + index) = 0;

    return result;
}

int main() {
    char *input = "2-5g-3-J";

    printf("%s\n", licenseKeyFormatting(input, 2));

    free(input);

    return 0;
}
