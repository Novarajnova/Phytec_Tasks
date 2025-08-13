//5. draw a flow chart to print the average of three numbers.


#include <stdio.h>
int main() {
    float a, b, c, avg;
    printf("Enter 3 numbers: ");
    scanf("%f%f%f", &a, &b, &c);
    avg = (a + b + c) / 3;
    printf("Average = %.2f\n", avg);
    return 0;
}

