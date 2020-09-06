#include <stdio.h>

int atoi(char *str)
{
    int result = 0;
    while (*str) {
        result = result * 10 + *str - '0';
        ++str;
    }
    return result;
}

int main()
{
    int result = 0;
    char int_str[10];
    char c;

    memset(int_str, 0, sizeof(int_str));
    while (scanf("%c", &c)) {
        if (c == '-' || c == '+' || c == '\n') {
            int int_value = atoi(int_str);
            result = (c == '-' ? (result - int_value) : (result + int_value));

            memset(int_str, 0, sizeof(int_str));

            if (c == '\n') {
                break;
            }
            continue;
        }

        if (c >= '0' && c <= '9') {
            int_str[strlen(int_str)] = c;
        }
    }

    printf("%d\n", result);

    return 0;
}
