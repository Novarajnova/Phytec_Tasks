//15. draw a flow chart to get marks of 5 subjects of a student and print grade A is above 80%, B is above 60%, C is above 40%, D is below 40%.

#include <stdio.h>
int main() {
    int m1, m2, m3, m4, m5;
    float avg;
    printf("Enter 5 subject marks: ");
    scanf("%d%d%d%d%d", &m1, &m2, &m3, &m4, &m5);

    avg = (m1 + m2 + m3 + m4 + m5) / 5.0;

    if(avg >= 80)
        printf("Grade A\n");
    else if(avg >= 60)
        printf("Grade B\n");
    else if(avg >= 40)
        printf("Grade C\n");
    else
        printf("Grade D\n");

    return 0;
}

