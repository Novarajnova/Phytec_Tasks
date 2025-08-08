//50.draw a flow chart to print second largest number among four numbers

#include <stdio.h>
int main() {
    int a[4], i, j, temp;
    printf("Enter 4 numbers: ");
    for(i = 0; i < 4; i++)
        scanf("%d", &a[i]);

    // Sort array
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3 - i; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Second largest = %d\n", a[2]);
    return 0;
}

