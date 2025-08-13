#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    long size, mid;
    char ch;
    fp = fopen("fileseek.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    mid = size / 2;
    fseek(fp, mid, SEEK_SET);
    printf("Data from middle of file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
    return 0;
}

