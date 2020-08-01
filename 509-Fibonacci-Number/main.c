#include <stdio.h>

int fib(int N) {
    if (N <= 1) {
        return N;
    }

    return (fib(N - 1) + fib(N - 2));
}

int main() {
    for (int i = 0 ; i < 30 ; ++ i) {
        printf("%dth fib = %d\n", i, fib(i));
    }
    return 0;
}
