//33. draw a flow chart to print given pattern
/*     BBBBB
        BBBB
         BBB
          BB
           B
*/

#include <stdio.h>
int main() {
    for(int i = 5; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("B");
        }
        printf("\n");
    }
    return 0;
}

