#include <stdio.h>

int getSingleStep(int target, int first)
{
    if (first == 1) {
        return target - 1;
    }
    if (first < 1) {
        return -1;
    }

    int ret = getSingleStep(first, target % first);
    if (ret > 0) {
        return target / first + ret;
    } else {
        return -1;
    }
}

int getSteps(int target)
{
    if (target == 1) {
        return 0;
    }

    int result = __INT_MAX__;
    for (int i = 1; i < target; ++i) {
        int step = getSingleStep(target, i);
        if (step >= 0) {
            result = step <= result ? step :result;
        }
    }
    return result;
}

int main()
{
    int k = 0;
    while (scanf("%d", &k) != EOF) {
        printf("%d\n", getSteps(k));
    }
    return 0;
}
