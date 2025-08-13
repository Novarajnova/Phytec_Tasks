#include <stdio.h>

int main() {
    FILE *source, *dest;
    char ch;

    const char *srcFile = "file.txt";
    const char *destFile = "file1_copy.txt";
    source = fopen(srcFile, "r");
    if (source == NULL) {
        printf("Cannot open source file '%s'\n", srcFile);
        return 1;
    }
    dest = fopen(destFile, "w");
    if (dest == NULL) {
        printf("Cannot create destination file '%s'\n", destFile);
        fclose(source);
        return 1;
    }
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied from '%s' to '%s' successfully.\n", srcFile, destFile);

    fclose(source);
    fclose(dest);
    return 0;
}

