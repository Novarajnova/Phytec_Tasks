//8. draw a flow chart to print the value of resistance ,when voltage and current values are provided.

#include <stdio.h>
int main() {
    float voltage, current, resistance;
    printf("Enter voltage and current: ");
    scanf("%f%f", &voltage, &current);
    resistance = voltage / current;
    printf("Resistance = %.2f Ohms\n", resistance);
    return 0;
}

