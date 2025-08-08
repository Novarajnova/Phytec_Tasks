//35.draw a flow chart to print given pattern
/*    AB
     AABB
    AAABBB
   AAAABBBB
  AAAAABBBBB
*/
   

#include <stdio.h>
int main() {
    int i, j, space;
    for(i = 1; i <= 5; i++) {
        // print leading spaces
        for(space = 1; space <= 5 - i; space++) {
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

