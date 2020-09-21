#include <stdio.h>
#include <stdlib.h>

#define MAX_OPRANDS   200
#define MAX_INPUT     500
#define MAX_OPERATORS 300

double get_double(char *str, size_t *index)
{
    char *end = NULL;
    double result = strtod((str + (*index)), &end);
    *index = end - str;

    return result;
}

double calcu(double a, double b, char operator)
{
    switch(operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

void flush_left(double *operands, int *operands_len, char *operators, int *operators_len)
{
    while (*operators_len > 0 && operators[*operators_len - 1] != '(') {
        operands[*operands_len - 2] = calcu(operands[*operands_len - 2], operands[*operands_len - 1], operators[*operators_len - 1]);
        --(*operands_len);
        --(*operators_len);
    }
    --(*operators_len);
}

void flush_high(double *operands, int *operands_len, char *operators, int *operators_len)
{
    while (*operators_len > 0 && (operators[*operators_len - 1] == '*' || operators[*operators_len - 1] == '/')) {
        operands[*operands_len - 2] = calcu(operands[*operands_len - 2], operands[*operands_len - 1], operators[*operators_len - 1]);
        --(*operands_len);
        --(*operators_len);
    }
}

void prase_express(char *src, double *operands, int *operands_len, char *operators, int *operators_len)
{
    size_t index = 0;
    int after_digits = 0;
    while (index < strlen(src)) {
        if ((!after_digits && src[index] == '-') || (src[index] >= '0' && src[index] <= '9')) {

            operands[*operands_len] = get_double(src, &index);
            ++(*operands_len);

            after_digits = 1;
        }

        if (src[index] == '+' || src[index] == '-') {
            if (operators[*operators_len - 1] == '*' || operators[*operators_len - 1] == '/') {
                flush_high(operands, operands_len, operators, operators_len);
            }
            operators[*operators_len] = src[index];
            ++(*operators_len);
            ++index;
            after_digits = 0;
        }

        if (src[index] == '(' || src[index] == '*' || src[index] == '/') {
            operators[*operators_len] = src[index];
            ++(*operators_len);
            ++index;
            after_digits = 0;
        }

        if (src[index] == ')') {
            flush_left(operands, operands_len, operators, operators_len);
            after_digits = 1;
            ++index;
        }
    }

    flush_left(operands, operands_len, operators, operators_len);
}

double get_result(char *str, int str_len)
{
    double result = 0.0;
    double operands[MAX_OPRANDS];
    char operators[MAX_OPERATORS];
    int operands_len = 0;
    int operators_len = 0;

    prase_express(str, operands, &operands_len, operators, &operators_len);

    return operands[0];
}

int main()
{
    char input[MAX_INPUT];
    while (scanf("%s", input)) {
        if (strlen(input) == 1 && input[0] == '0') {
            break;
        }

        printf("%.2f\n", get_result(input, strlen(input)));
    }
    return 0;
}
