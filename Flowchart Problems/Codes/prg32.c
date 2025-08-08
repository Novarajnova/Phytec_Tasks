//32.draw a flow chart to print given partten
/*  AAAAA
    AAAA
    AAA
    AA
    A  */
    
#include <stdio.h>
int main() {
    for(int i = 5; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("A");
        }
        printf("\n");
    }
    return 0;
}

