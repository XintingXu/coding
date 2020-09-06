#include <stdio.h>

void reverse(char *str)
{
    char *end = str + strlen(str) - 1;
    while (str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;

        ++str;
        --end;
    }
}

int main()
{
    int isFirst = 1;
    char temp[100];

    while (scanf("%s", temp) != EOF) {
        reverse(temp);
        if (!isFirst) {
            printf(" ");
        }
        printf("%s", temp);
        isFirst = 0;
    }
    printf("\n");

    return 0;
}
