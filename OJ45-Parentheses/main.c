#include <stdio.h>

int main()
{
    char get;
    int left_miss = 0;
    int right_miss = 0;

    while (scanf("%c", &get) != EOF) {
        if (get == '\n') {
            printf("%d\n", left_miss + right_miss);
            left_miss = 0;
            right_miss = 0;
        }

        if (get == '(') {
            ++right_miss;
        }
        if (get == ')') {
            if (right_miss == 0) {
                ++left_miss;
            } else {
                --right_miss;
            }
        }
    }
    return 0;
}
