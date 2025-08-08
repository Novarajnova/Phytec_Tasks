//48.draw a flow chart to print the first 20 prime numbers.

#include <stdio.h>
int main() {
    int count = 0, num = 2, i, isPrime;

    while(count < 20) {
        isPrime = 1;
        for(i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime) {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    return 0;
}

