#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    char op = argv[2][0];
    int num2 = atoi(argv[3]);
    int result;

    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = sub(num1, num2);
            break;
        case '*':
            result = mul(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Error: Unknown operator '%c'\n", op);
            return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}
