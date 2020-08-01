#include <stdio.h>
#include <stdlib.h>

char *convertToBase7(int num){
    char *result = (char *)malloc(sizeof(char) * 11);
    if (num == 0) {
        *result = '0';
        *(result + 1) = 0;
        return result;
    }

    int result_pos = 0;
    int num_loop = num >= 0 ? num : -num;

    while (num_loop != 0) {
        *(result + result_pos) = '0' + num_loop % 7;
        num_loop /= 7;
        ++ result_pos;
    }
    if (num < 0) {
        *(result + result_pos) = '-';
        ++ result_pos;
    }

    for (int i = 0 ; i < result_pos / 2 ; ++ i) {
        char temp = *(result + i);
        *(result + i) = *(result + result_pos - i - 1);
        *(result + result_pos - i - 1) = temp;
    }

    *(result + result_pos) = 0;
    return result;
}

int main() {
    return 0;
}
