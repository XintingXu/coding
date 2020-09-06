#include <stdio.h>

#define ADD(a, b) a ^ b

int max_arrange(int *data, int arrange, int N)
{
    int SUM[2] = {0, 0};
    int sum[2] = {0, 0};

    for (int index = 0; index < N; ++index) {
        if (arrange & (1 << index)) {
            SUM[1] = ADD(SUM[1], data[index]);
            sum[1] += data[index];
            continue;
        }

        SUM[0] = ADD(SUM[0], data[index]);
        sum[0] += data[index];
    }

    if (SUM[0] == SUM[1]) {
        return sum[1] >= sum[0] ? sum[1] : sum[0];
    }
    return 0;
}

int main()
{
    int N = 0;
    int C[20];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &C[i]);
    }

    int result = 0;
    for (int arrange = 1; arrange < (1 << N) - 1; ++arrange) {
        int temp = max_arrange(C, arrange, N);
        result = result >= temp ? result : temp;
    }

    if (result) {
        printf("%d\n", result);
    } else {
        printf("NO\n");
    }

    return 0;
}
