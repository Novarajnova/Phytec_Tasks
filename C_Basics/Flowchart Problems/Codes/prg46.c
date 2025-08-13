//46.draw a flow chart to get 10 numbers from the user and print the ascending order A[0]

#include <stdio.h>
int main() {
    int a[10], temp;
    printf("Enter 10 numbers: ");
    for(int i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    // Bubble sort
    for(int i = 0; i < 10 - 1; i++) {
        for(int j = 0; j < 10 - i - 1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}

