///6. draw a flow chart to print perimeter of a circle.

#include <stdio.h>
#define PI 3.14
int main() {
    float radius, perimeter;
    printf("Enter radius: ");
    scanf("%f", &radius);
    perimeter = 2 * PI * radius;
    printf("Perimeter = %.2f\n", perimeter);
    return 0;
}

