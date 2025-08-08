//49. Draw a flow chart to find the largest number and smallest number among four given numbers .

#include <stdio.h>
int main() {
    int a, b, c, d;
    printf("Enter 4 numbers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    int max = a, min = a;

    if(b > max) max = b;
    if(c > max) max = c;
    if(d > max) max = d;

    if(b < min) min = b;
    if(c < min) min = c;
    if(d < min) min = d;

    printf("Largest = %d, Smallest = %d\n", max, min);
    return 0;
}

