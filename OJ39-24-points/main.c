#include <stdio.h>

#define ABS(a) (a >= 24.0 ? a - 24.0 : 24.0 - a)

int praseChar(char a)
{
    int ret = 0;
    switch (a) {
        case 'A':
            ret = 1;
            break;
        case 'T':
            ret = 10;
            break;
        case 'J':
            ret = 11;
            break;
        case 'Q':
            ret = 12;
            break;
        case 'K':
            ret = 13;
            break;
        default:
            ret = a - '1';
    }
    return ret;
}

int thirdStep(double a, double b)
{
    if (ABS(a + b) < 1E-6 || ABS(a * b) < 1E-6) {
        return 1;
    }
    if (((a > b) && (ABS(a - b) < 1E-6)) || ((b != 0) && (ABS(a / b) < 1E-6))) {
        return 1;
    }

    return 0;
}

int secondStep(double a, double b, double c)
{
    if (thirdStep(a + b, c) || thirdStep(a, b + c) || thirdStep(a * b, c) || thirdStep(a, b * c)) {
        return 1;
    }
    if (((a >= b) && thirdStep(a - b, c)) || ((b != 0) && (thirdStep(a / b, c)))) {
        return 1;
    }
    if (((b >= c) && thirdStep(a, b - c)) || ((c != 0) && (thirdStep(a, b / c)))) {
        return 1;
    }

    return 0;
}

int firstStep(double a, double b, double c, double d)
{
    if (secondStep(a + b, c, d) || secondStep(a, b + c, d) || secondStep(a, b, c + d)) {
        return 1;
    }

    if (secondStep(a * b, c, d) || secondStep(a, b * c, d) || secondStep(a, b, c * d)) {
        return 1;
    }

    if (((a >= b) && secondStep(a - b, c, d)) || ((b >= c) && secondStep(a, b - c, d)) ||
            ((c >= d) && secondStep(a, b, c - d))) {
        return 1;
    }

    if (((b != 0) && secondStep(a / b, c, d)) || ((c != 0) && secondStep(a, b / c, d)) ||
            ((d != 0) && secondStep(a, b, c / d))) {
        return 1;
    }

    return 0;
}

int main()
{
    char a, b, c, d;
    int A, B, C, D;
    while (scanf("%c %c %c %c", &a, &b, &c, &d) != EOF) {
        A = praseChar(a);
        B = praseChar(b);
        C = praseChar(c);
        D = praseChar(d);
        scanf("%c", &a);

        if (firstStep(A, B, C, D)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
