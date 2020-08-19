#include <stdio.h>
#include <string.h>

#define RESULT_SIZE 10000
unsigned int result[RESULT_SIZE];
const unsigned int g_sector_length = 10000;

void multi(const unsigned int factor)
{
    unsigned int carry = 0;
    for (int index = 0; index < RESULT_SIZE; ++index) {
        unsigned int temp = result[index];
        temp *= factor;
        temp += carry;
        carry = temp / g_sector_length;
        temp %= g_sector_length;
        result[index] = temp;
    }
}

void getNTimes(const unsigned int N)
{
    memset(result, (unsigned int)0, sizeof(result));
    result[0] = 1;
    for (unsigned int i = 1; i <= N; ++i) {
        multi(i);
    }
}

void printResult()
{
    int end = RESULT_SIZE - 1;
    while (end >= 0 && result[end] == 0) {
        --end;
    }

    printf("%d", result[end]);
    --end;
    while (end >= 0) {
        printf("%04d", result[end]);
        --end;
    }
    printf("\n");
}

int main()
{
    unsigned int N;
    while(scanf("%d", &N) != EOF) {
        getNTimes(N);

        printResult();
    }
    return 0;
}
