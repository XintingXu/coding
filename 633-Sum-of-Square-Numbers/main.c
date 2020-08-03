#include <stdio.h>
#include <math.h>

#define bool short
#define true 1
#define false 0

bool judgeSquareSum(int c){
    for (int i = 0 ; i < 46340 && i * i <= c; ++ i) {
        int remain = c - i * i;
        int remain_sqrt = pow(remain, 0.5);

        if (remain_sqrt * remain_sqrt == remain) {
            return true;
        }
    }

    return false;
}

int main() {
    for (int i = 0 ; i <= 100 ; ++ i) {
        printf("%d -> %d\n", i, judgeSquareSum(i));
    }

    return 0;
}
