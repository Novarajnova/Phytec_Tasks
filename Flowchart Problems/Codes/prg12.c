//12. draw a flow chart to read two numbers from user and print bigger value.

#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    if(a > b)
        printf("%d is bigger\n", a);
    else
        printf("%d is bigger\n", b);

    return 0;
}

