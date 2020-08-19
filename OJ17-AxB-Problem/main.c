#include <stdio.h>

#define BUFFER_SIZE 1100
#define RESULT_SIZE 1210000

char A[BUFFER_SIZE];
char B[RESULT_SIZE];
char result[RESULT_SIZE];

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

void add(char *dst, char *src, int dst_len, int src_len)
{
    int carry = 0;
    int index = 0;
    for (index = 0; index < dst_len && index < src_len && src[index]; ++index) {
        int dst_i = dst[index] == 0 ? 0 : dst[index] - '0';
        int src_i = src[index] == 0 ? 0 : src[index] - '0';
        int temp = dst_i + src_i + carry;
        dst[index] = temp % 10 + '0';
        carry = temp / 10;
    }

    if (carry && index + 1 < dst_len) {
        dst[index] = carry + '0';
        dst[index + 1] = 0;
    }
}

void multi_int(char *src, int factor, int src_len)
{
    int carry = 0;
    int index = 0;
    for (index = 0; index < src_len && src[index]; ++index) {
        int temp = (src[index] - '0') * factor + carry;
        src[index] = temp % 10 + '0';
        carry = temp / 10;
    }

    if (carry && index + 1 < src_len) {
        src[index] = carry + '0';
        src[index + 1] = 0;
    }
}

void multi()
{
    strrev(A);
    strrev(B);

    if (A[strlen(A) - 1] == '-') {
        A[strlen(A) - 1] = 0;
    }
    if (B[strlen(B) - 1] == '-') {
        B[strlen(B) - 1] = 0;
    }

    char temp_result[10][BUFFER_SIZE];
    memset(temp_result, 0, 10 * BUFFER_SIZE);
    for (int i = 0; i < 10; ++i) {
        memcpy(temp_result[i], A, BUFFER_SIZE);
        multi_int(temp_result[i], i, BUFFER_SIZE);
    }

    for (size_t index = 0; index < strlen(B); ++index) {
        add(&result[index], temp_result[B[index] - '0'], RESULT_SIZE - index, BUFFER_SIZE);
    }

    int index = strlen(result) - 1;
    while(index > 0 && result[index] == '0') {
        --index;
    }
    result[index + 1] = 0;

    strrev(result);
}

int main()
{
    while (scanf("%s%s", A, B) != EOF) {
        memset(&A[strlen(A)], 0, BUFFER_SIZE - strlen(A));
        memset(&B[strlen(B)], 0, BUFFER_SIZE - strlen(B));
        memset(result, 0, RESULT_SIZE);

        int isNegtive = 0;
        if (A[0] == '-') {
            isNegtive ^= 1;
        }
        if (B[0] == '-') {
            isNegtive ^= 1;
        }

        multi();
        if (isNegtive) {
            printf("-");
        }
        printf("%s\n", result);
    }
    return 0;
}
