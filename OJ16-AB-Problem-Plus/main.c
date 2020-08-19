#include <stdio.h>

#define BUFFER_SIZE 1100
char A[BUFFER_SIZE];
char B[BUFFER_SIZE];
int isNegtive = 0;

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

void changeOrder()
{
    if ((strlen(B) > strlen(A)) || (strlen(A) == strlen(B) && strcmp(A, B) < 0)) {
        isNegtive = 1;
        char temp[1100];
        memcpy(temp, A, BUFFER_SIZE);
        memcpy(A, B, BUFFER_SIZE);
        memcpy(B, temp, BUFFER_SIZE);
    }
}

void sub()
{
    char *a = A;
    char *b = B;
    int isBorrow = 0;

    while(*a || *b) {
        int a_i = *a ? *a - '0' : 0;
        int b_i = *b ? *b - '0' : 0;

        if (a_i < b_i + isBorrow) {
            *a = (a_i - b_i - isBorrow + 10) % 10 + '0';
            isBorrow = 1;
        } else {
            *a = (a_i - b_i - isBorrow + 10) % 10 + '0';
            isBorrow = 0;
        }

        ++a;
        ++b;
    }

    int index = 0;
    for (index = strlen(A) - 1; index > 0; --index) {
        if (A[index] != '0') {
            break;
        }
    }
    A[index + 1] = 0;
    memset(&A[strlen(A)], 0, BUFFER_SIZE - strlen(A));
}

int main()
{
    int T = 0;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        scanf("%s%s", A, B);
        printf("Case %d:\n", i + 1);
        printf("%s - %s = ", A, B);

        memset(A + strlen(A), 0, BUFFER_SIZE - strlen(A));
        memset(B + strlen(B), 0, BUFFER_SIZE - strlen(B));
        isNegtive = 0;

        changeOrder();

        strrev(A);
        strrev(B);

        sub();

        strrev(A);
        if (isNegtive) {
            printf("-");
        }
        printf("%s\n", A);
    }

    return 0;
}
