//2. draw a flow chart to print area of rectangle.

#include <stdio.h>
int main() {
    int length, breadth, area;
    printf("Enter length and breadth: ");
    scanf("%d%d", &length, &breadth);
    area = length * breadth;
    printf("Area = %d\n", area);
    return 0;
}

