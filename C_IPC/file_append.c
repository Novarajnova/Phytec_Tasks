#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("file.txt", "a");

    if(fp == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    fprintf(fp, "\nAppended line: Yes, I am good!");
    fclose(fp);

    printf("Data appended successfully.\n");
    return 0;
}

