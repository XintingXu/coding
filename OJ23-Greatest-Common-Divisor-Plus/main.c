#include <stdio.h>

int combinations[20010];

void generate_combinations(int n)
{
    for (int i = 0; i <= n; ++i) {
        combinations[i] = 1;
        for (int j = i - 1; j > 0; --j) {
            combinations[j] = combinations[j] + combinations[j - 1];
        }
    }
}

void getDivisor(int n)
{
    int i = 0;
    for (i = combinations[1] ; i > 0; --i) {
        int isNotMod = 0;
        for (int index = 1; index < n; index += 2) {
            if (combinations[index] % i != 0) {
                ++isNotMod;
                break;
            }
        }
        if (isNotMod) {
            continue;
        } else {
            break;
        }
    }

    printf("%d\n", i);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    memset(combinations, 0, sizeof(combinations));

    generate_combinations(2 * n);

    getDivisor(2 * n);

    return 0;
}
