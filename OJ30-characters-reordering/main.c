#include <stdio.h>

int get_combinations(int total, int target)
{
    int combinations[20];
    memset(combinations, 0, sizeof(combinations));

    combinations[0] = 1;
    for (int i = 0; i <= total; ++i) {
        combinations[i] = 1;
        for (int j = i - 1; j > 0; --j) {
            combinations[j] = combinations[j] + combinations[j - 1];
        }
    }

    return combinations[target];
}

int main()
{
    int characters[30];
    int sum = 0;
    memset(characters, 0, sizeof(characters));

    char character;
    while (scanf("%c", &character) != EOF && character != '\n') {
        ++characters[character - 'A'];
        ++sum;
    }

    int result = 1;
    for (int i = 0; i < 26; ++i) {
        result *= get_combinations(sum, characters[i]);
        sum -= characters[i];
    }

    printf("%d\n", result);

    return 0;
}
