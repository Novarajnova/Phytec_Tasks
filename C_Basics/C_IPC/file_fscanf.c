#include <stdio.h>

int main() {
    FILE *fp;
    int id;
    char name[50];
    float salary;
    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }
    while (fscanf(fp, "%d %s %f", &id, name, &salary) != EOF) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", id, name, salary);
    }

    fclose(fp);
    return 0;
}

