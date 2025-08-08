#include <stdio.h>

int main() {
    FILE *fp;
    const char *filename = "file.txt";

    // Try opening file in read mode
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File '%s' does not exist or cannot be opened.\n", filename);
    } else {
        printf("File '%s' exists and opened successfully!\n", filename);
        fclose(fp);
    }

    return 0;
}

