//27. draw a flow chart to print the series of numbers 2,4,4,8,6,12,8,16,10,20.

#include <stdio.h>
int main() {
    int even = 2, mul = 4;
    for(int i = 1; i <= 10; i++) {
        if(i % 2 != 0) {
            printf("%d ", even);   // odd positions: 2, 4, 6, 8, 10
            even += 2;
        } else {
            printf("%d ", mul);    // even positions: 4, 8, 12, 16, 20
            mul += 4;
        }
    }
    return 0;
}

