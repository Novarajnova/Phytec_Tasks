#include <stdio.h>

int main() {
    FILE *fp;
    char ch;
    int lines = 0;

    const char *filename = "file.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File '%s' cannot be opened or doesn't exist.\n", filename);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(fp);

    printf("Total number of lines in '%s': %d\n", filename, lines);
    return 0;
}

