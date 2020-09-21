#include <stdio.h>

#define min(a, b) (a > b ? b : a)
char numbers[1010][20];

int strcmpn(int indexa, int indexb, int len)
{
    for (int i = 0; i < len && i < sizeof(numbers[0]); ++i) {
        if (numbers[indexa][i] != numbers[indexb][i]) {
            return 1;
        }
    }
    return 0;
}

int str_compare(int n)
{
    for (int start = 0; start < n - 1; ++start) {
        for (int end = start + 1; end < n; ++end) {
            int len = min(strlen(numbers[start]), strlen(numbers[end]));
            if (strcmpn(start, end, len) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF && n != 0) {
        memset(numbers, 0, sizeof(numbers));
        for (int i = 0; i < n; ++i) {
            scanf("%s", numbers[i]);
        }
        if (str_compare(n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
