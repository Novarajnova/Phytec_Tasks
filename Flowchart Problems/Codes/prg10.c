//10. draw a flow chart to take the values ofi1,i2,i3,i4,i5,i6 current values following from the point and calcute sum of current.

#include <stdio.h>
int main() {
    float i1, i2, i3, i4, i5, i6, total;
    printf("Enter 6 current values: ");
    scanf("%f%f%f%f%f%f", &i1, &i2, &i3, &i4, &i5, &i6);
    total = i1 + i2 + i3 + i4 + i5 + i6;
    printf("Total Current = %.2f A\n", total);
    return 0;
}

