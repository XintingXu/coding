#include <stdio.h>

void praseR(char *r, int r_len, int *prasedR, int *digits)
{
    while (r_len > 0 && r[r_len - 1] == '0') {
        --r_len;
    }
    for (int index = 0; index < r_len; ++index) {
        if (r[index] == '.') {
            *digits = r_len - index - 1;
        } else {
            *prasedR *= 10;
            *prasedR += r[index] - '0';
        }
    }
}

void multiply(int *result, int result_len, const int factor)
{
    int carry = 0;
    for (int index = 0; index < result_len; ++index) {
        result[index] *= factor;
        result[index] += carry;
        carry = result[index] / 10;
        result[index] %= 10;
    }
}

void exponen(int *result, int result_len, int n, int r)
{
    for (int i = 0; i < n; ++i) {
        multiply(result, result_len, r);
    }
}

void printResult(int *result, int result_len, int digits)
{
    do {
        --result_len;
    } while (result_len >= 0 && result[result_len] == 0);

    while (result_len > digits - 1) {
        printf("%d", result[result_len]);
        --result_len;
    }
    printf(".");
    while (result_len < digits - 1) {
        printf("0");
        --digits;
    }

    while (result_len >= 0) {
        printf("%d", result[result_len]);
        --result_len;
    }
    printf("\n");
}

/*
 * get R^n, 0.0 < R < 99.999, 0 < n <= 25
*/
int main()
{
    char r[7];
    int n = 0;
    while (scanf("%s", r) && scanf("%d", &n)) {
        int prased_r = 0;
        int digits = 0;

        praseR(r, strlen(r), &prased_r, &digits);

        int result[120];
        memset(result, 0, sizeof(result));
        result[0] = 1;
        exponen(result, sizeof(result)/sizeof(result[0]), n, prased_r);

        printResult(result, sizeof(result)/sizeof(result[0]), digits * n);
    }
    return 0;
}
