#include <stdio.h>

int get_solutions(int target)
{
    int result = 0;
    for (int count_3 = 0; count_3 <= target / 3; ++count_3) {
        for (int count_2 = 0; count_2 <= (target - count_3 * 3) / 2; ++count_2) {
            ++result;
        }
    }

    return result;
}

int main()
{
    int target = 0;
    while (scanf("%d", &target) != EOF) {
        printf("%d\n", get_solutions(target));
    }
    return 0;
}
