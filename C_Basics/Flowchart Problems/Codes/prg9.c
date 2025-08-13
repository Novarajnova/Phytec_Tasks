//9. draw a flow chart to print the power when the current and resistance values are provided.

#include <stdio.h>
int main() {
    float current, resistance, power;
    printf("Enter current and resistance: ");
    scanf("%f%f", &current, &resistance);
    power = current * current * resistance;
    printf("Power = %.2f W\n", power);
    return 0;
}

