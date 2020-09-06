#include <stdio.h>

char g_parentheses[100];
int g_stack_length = 0;

int check(char c)
{
    if (c == '(') {
        g_parentheses[g_stack_length] = c;
        ++g_stack_length;
        return 0;
    }

    if (g_stack_length > 0 && g_parentheses[g_stack_length - 1] == '(') {
        --g_stack_length;
        return 0;
    }

    return 1;
}

int main()
{
    memset(g_parentheses, 0, sizeof(g_parentheses));
    g_stack_length = 0;

    char temp;
    while (scanf("%c", &temp) != EOF && temp != '\n') {
        if ((temp == '(' || temp == ')') && check(temp)) {
            printf("NO\n");
            return 0;
        }
    }

    if (g_stack_length == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
