#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile, *outfile;
    long file_size;
    char *buffer;
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        perror("Error opening input file");
        return 1;
    }
    fseek(infile, 0, SEEK_END);
    file_size = ftell(infile);
    rewind(infile);
    buffer = (char *)malloc(file_size);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(infile);
        return 1;
    }
    fread(buffer, 1, file_size, infile);
    fclose(infile);
    outfile = fopen("reversed.txt", "w");
    if (outfile == NULL) {
        perror("Error opening output file");
        free(buffer);
        return 1;
    }
    for (long i = file_size - 1; i >= 0; i--) {
        fputc(buffer[i], outfile);
    }

    printf("File content reversed and saved to 'reversed.txt'.\n");

    fclose(outfile);
    free(buffer);
    return 0;
}

