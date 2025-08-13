//29. draw a flow chart to print first n multiplication table from 2.

#include <stdio.h>
int main() {
    int n;
    printf("Enter n (number of tables): ");
    scanf("%d", &n);

    for(int table = 2; table < 2 + n; table++) {
        printf("\nMultiplication Table of %d\n", table);
        for(int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", table, i, table * i);
        }
    }
    return 0;
}

