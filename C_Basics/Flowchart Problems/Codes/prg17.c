//17. draw a flow chart to get age of a person to print greeting message if age<=5 nice child, age<=10 nice kid, age<=15 tennagers, age<=25 young dynamic, age<=50 middle age, age<=50 old.

#include <stdio.h>
int main() {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);

    if(age <= 5)
        printf("Nice child\n");
    else if(age <= 10)
        printf("Nice kid\n");
    else if(age <= 15)
        printf("Teenager\n");
    else if(age <= 25)
        printf("Young dynamic\n");
    else if(age <= 50)
        printf("Middle age\n");
    else
        printf("Old\n");

    return 0;
}

