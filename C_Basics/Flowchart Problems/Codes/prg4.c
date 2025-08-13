//4. draw a flow chart to print area of square.

#include <stdio.h>
int main() {
    int side, area;
    printf("Enter side of square: ");
    scanf("%d", &side);
    area = side * side;
    printf("Area = %d\n", area);
    return 0;
}

