//43.draw a flow chart to print chech whether the given number is palindrome or not.

#include <stdio.h>
int main() {
    int n, rev = 0, temp, rem;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while(temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }
    if(n == rev)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}

