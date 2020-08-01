#include <stdio.h>
#include <math.h>
/*
the count of coins at stage C(i) = (1 + i) * i / 2

one method is searching through half-seperation, from [0, n], until i meets the requirement C(i - 1) < n <= C(i)

another method, is searching from (C(i) * 2) ^ (1/2), which is the reversing of C(i)

the third way, is calculate with math iteration, f(i) = (1 + i) * i / 2 - C(i), f'(i) = i + 1/2
F(i) = F(i) - f(i)/f'(i), start from C(i) / 2
*/

/*  method two
int arrangeCoins(int n) {
    long long n_long = n;
    long long base = n_long * 2;
    base = pow(base, 0.5);

    while (1) {
        long long step = ((1 + base) * base ) / 2;
        if (step > n_long) {
            break;
        }
        ++ base;
    }

    return (int)(base - 1);
}
*/

/*
the first, half-way search
*/
/*
int arrangeCoins(int n) {
    long long begin = 0, end = n;
    while (begin < end) {
        long long middle = (begin + end) / 2;
        long long step = (1 + middle) * middle / 2;

        if (step < n) {
            if (begin == middle) {
                step = (1 + end) * end / 2;
                if (step == n) {
                    begin = end;
                } else {
                    -- end;
                }
            } else {
                begin = middle;
            }
        } else {
            end = middle;
        }
    }
    return (int)begin;
}
*/

/* f(i) = (1 + i) * i / 2 - C(i), f'(i) = i + 1/2, F(i) = F(i) - f(i)/f'(i) */
int arrangeCoins(int n) {
    double lastF = n >> 1;
    while (1) {
        double f_i = (1 + lastF) * lastF / 2 - n;
        double f_i_2 = lastF + 0.5;
        double step_F = lastF - f_i / f_i_2;

        if((long long)(lastF * 10) == (long long)(step_F * 10)) {
            break;
        }

        lastF = step_F;
    }

    return (int)lastF;
}

int main() {
    for (int i = 1804289383 ; i < 1804289390; ++i) {
        printf("i = %4d,\tstairs = %3d\n", i, arrangeCoins(i));
    }

    return 0;
}
