//16. draw a flow chart to get age of a person to print wheather he is eligible for DL or not.

#include <stdio.h>
int main() {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);

    if(age >= 18)
        printf("Eligible for Driving License\n");
    else
        printf("Not eligible\n");

    return 0;
}

