#include <stdio.h>

#define min(a, b) (a >= b? b : a)

int getPaint(char *src, int src_len, int point)
{
    int result = 0;
    for (int index = 0; index < point; ++index) {
        if (src[index] != 'R') {
            ++result;
        }
    }

    for (int index = src_len - 1; index >= point; --index) {
        if (src[index] != 'G') {
            ++result;
        }
    }

    return result;
}

int main()
{
    char colour[60];
    memset(colour, 0, sizeof(colour));

    scanf("%s", colour);
    int L = strlen(colour);

    int result_min = __INT_MAX__;
    for (int point = 0; point <= L; ++point) {
        result_min = min(getPaint(colour, L, point), result_min);
    }

    printf("%d\n", result_min);

    return 0;
}
