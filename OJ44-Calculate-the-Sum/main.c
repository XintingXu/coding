#include <stdio.h>

void get_digits(int *dest)
{
    char temp;
    while(scanf("%c", &temp) != EOF && temp != '\n') {
        ++dest[temp - '0'];
    }
}

int get_results(int *m, int *n)
{
    int result = 0;
    for (int index = 1; index < 10; ++index) {
        if (!n[index]) {
            continue;
        }

        for (int source = 1; source < 10; ++source) {
            result += m[source] * source % index;
        }
    }

    return result;
}

int main()
{
    int groups = 0;
    int m[10];
    int n[10];

    scanf("%d", &groups);
    getchar();
    for (int count = 0; count <groups; ++count) {
        memset(m, 0, sizeof(m));
        memset(n, 0, sizeof(n));

        get_digits(m);
        get_digits(n);

        printf("%d\n", get_results(m, n));
    }

    return 0;
}
