//3. draw a flow chart to print perimeter of a square.

#include <stdio.h>
int main() {
    int side, perimeter;
    printf("Enter side of square: ");
    scanf("%d", &side);
    perimeter = 4 * side;
    printf("Perimeter = %d\n", perimeter);
    return 0;
}

