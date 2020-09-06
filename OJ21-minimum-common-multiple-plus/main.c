#include <stdio.h>

int result[500];

int isMod(int n) {
    int remain = 0;
    for (int index = sizeof(result) / sizeof(result[0]) - 1; index >= 0; --index) {
        remain = (remain * 10 + result[index]) % n;
    }

    return remain ? 0 : 1;
}

void multiply(int factor) {
    int remain = 0;
    for (int index = 0; index < sizeof(result) / sizeof(result[0]); ++index) {
        result[index] = result[index] * factor + remain;
        remain = result[index] / 10;
        result[index] %= 10;
    }
}

void multiplus(int n) {
    if (isMod(n)) {
        return;
    }

    int moded = 1;

    for (int i = n - 1; i >= 2; --i) {
        if (n % i == 0 && isMod(moded * i)) {
            n /= i;
            moded *= i;
        }
    }

    multiply(n);
}

void printResult() {
    int end = sizeof(result) / sizeof(result[0]) - 1;
    while (end > 0 && result[end] == 0) {
        --end;
    }

    while (end >= 0) {
        printf("%d", result[end]);
        --end;
    }

    printf("\n");
}

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF) {\
        memset(result, 0, sizeof(result));
        result[0] = 1;

        for (int i = 1; i <= n; ++i) {
            multiplus(i);
        }

        printResult();
    }
    return 0;
}
