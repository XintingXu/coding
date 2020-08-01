#include <stdio.h>

int findComplement(int num){
    int result = 0;
    int temp_num = num;
    while (temp_num) {
        result = result << 1;
        result += 1;
        temp_num = temp_num >> 1;
    }
    return result ^ num;
}

int main() {
    printf("Hello World!\n");
    return 0;
}
