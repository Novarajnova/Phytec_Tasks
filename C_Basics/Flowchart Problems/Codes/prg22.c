//22. draw a flow chart to print all the even numbers in range.

#include <stdio.h>
int main() {
    int start, end;
    printf("Enter range (start end): ");
    scanf("%d%d", &start, &end);

    for(int i = start; i <= end; i++) {
        if(i % 2 == 0)
            printf("%d ", i);
    }
    return 0;
}

