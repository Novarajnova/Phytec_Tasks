//14. draw a flow chart to read the three numbers from the user and print the biggest value.

#include <stdio.h>
int main() {
    int a, b, c;
    printf("Enter 3 numbers: ");
    scanf("%d%d%d", &a, &b, &c);

    if(a > b && a > c)
        printf("%d is biggest\n", a);
    else if(b > c)
        printf("%d is biggest\n", b);
    else
        printf("%d is biggest\n", c);

    return 0;
}

