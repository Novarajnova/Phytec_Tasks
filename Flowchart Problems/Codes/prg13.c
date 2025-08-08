//13. draw a flow chart to print wheather the given number is positive or negative.

#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num >= 0)
        printf("Positive number\n");
    else
        printf("Negative number\n");

    return 0;
}

