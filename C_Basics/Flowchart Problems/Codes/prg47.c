//47.draw a flow chart to check if a given year is a leapyear or not.

#include <stdio.h>
int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("Leap Year\n");
    else
        printf("Not Leap Year\n");

    return 0;
}

