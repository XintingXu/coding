#include <stdio.h>

char A[1100];
char B[1100];

void strrev(char *src)
{
    char *end = src + strlen(src) - 1;
    while (src < end) {
        char temp = *src;
        *src = *end;
        *end = temp;

        ++src;
        --end;
    }
}

void plus()
{
    int pre_plus = 0;
    char *a = A;
    char *b = B;

    while (*a || *b || pre_plus) {
        int a_i = *a ? *a - '0' : 0;
        int b_i = *b ? *b - '0' : 0;

        *a = (a_i + b_i + pre_plus) % 10 + '0';
        pre_plus = (a_i + b_i + pre_plus) / 10;

        ++a;
        ++b;
    }

    *a = 0;
}

int main()
{
    int T = 0;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        scanf("%s%s", A, B);
        printf("Case %d:\n", i + 1);
        printf("%s + %s = ", A, B);

        memset(A + strlen(A), 0, sizeof(A) - strlen(A));
        memset(B + strlen(B), 0, sizeof(B) - strlen(B));

        strrev(A);
        strrev(B);
        plus();
        strrev(A);
        printf("%s\n", A);
    }

    return 0;
}
