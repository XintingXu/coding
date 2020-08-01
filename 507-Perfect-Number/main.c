#include <stdio.h>

#define bool short
#define true 1
#define false 0

bool checkPerfectNumber(int num) {
    if (num < 2) {
        return false;
    }

    int sum = 1;

    for (int i = 2 ; i * i <= num ; ++ i) {
        if (num % i == 0) {
            sum += i;
            sum += i * i == num ? 0 : num / i;
        }
        if (sum > num) {
            break;
        }
    }

    if (sum == num) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}
