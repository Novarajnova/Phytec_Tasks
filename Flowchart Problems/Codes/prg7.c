//7. draw a flow chart to print the sum of 5 subjects of students.

#include <stdio.h>
int main() {
    int s1, s2, s3, s4, s5, sum;
    printf("Enter marks in 5 subjects: ");
    scanf("%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5);
    sum = s1 + s2 + s3 + s4 + s5;
    printf("Total = %d\n", sum);
    return 0;
}

