#include <stdio.h>
#include <string.h>

void strAlign(char *str, int str_len)
{
    int data = 0;
    for (int index = 0; index < str_len; ++index) {
        if (str[index] == ' ') {
            continue;
        }

        if (str[index] >= 'A' && str[index] <= 'Z') {
            str[data] = str[index] - 'A' + 'a';
        } else {
            str[data] = str[index];
        }
        ++data;
    }
    str[data] = 0;
}

int main()
{
    char a[110];
    char b[110];

    while (gets(a) && gets(b)) {
        strAlign(a, strlen(a));
        strAlign(b, strlen(b));

        if (strcmp(a, b) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
