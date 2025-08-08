//26. draw a flow chart to print the series of 5,10,15,20,.........n numbers.

#include <stdio.h>
int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    for(int i = 5; i <= n; i += 5)
        printf("%d ", i);

    return 0;
}

