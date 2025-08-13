//11. Draw a flow chart to read the number of digits in given number.

#include <stdio.h>
int main() {
    int num, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num == 0) count = 1;  // special case

    while(num != 0) {
        num = num / 10;
        count++;
    }

    printf("Number of digits = %d\n", count);
    return 0;
}

