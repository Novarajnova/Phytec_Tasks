//34.draw a flow chart to print given pattern
/*     AAAAABBBBB
        AAAABBBB
         AAABBB
          AABB
           AB    */
       
#include <stdio.h>
int main() {
    int i, j, space;
    for(i = 5; i >= 1; i--) {
        // print leading spaces
        for(space = 0; space < 5 - i; space++) {
            printf(" ");
        }
        // print A's
        for(j = 1; j <= i; j++) {
            printf("A");
        }
        // print B's
        for(j = 1; j <= i; j++) {
            printf("B");
        }
        printf("\n");
    }
    return 0;
}

