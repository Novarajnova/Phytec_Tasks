//21. draw a flow chart to print first 30 odd numbers.

#include <stdio.h>
int main() {
    for(int i = 1; i <= 30; i++)
        printf("%d ", i * 2 - 1);
    return 0;
}

