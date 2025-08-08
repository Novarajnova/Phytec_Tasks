//45.draw a flow chart to print decimal value of hexa number.

#include <stdio.h>
int main() {
    int decimal;
    char hex[20];
    printf("Enter Hexadecimal: ");
    scanf("%s", hex);
    sscanf(hex, "%x", &decimal);
    printf("Decimal = %d\n", decimal);
    return 0;
}

