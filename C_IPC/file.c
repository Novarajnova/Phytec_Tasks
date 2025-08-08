#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[256];

    fp = fopen("file.txt", "r");
    
    if(fp == NULL) {
        printf("Error: file not found\n");
        return 1; 
    } else {
        printf("File is available.\n");
        while(fgets(buffer, sizeof(buffer), fp)) {
            printf("%s", buffer);
        }

        fclose(fp);
    }

    return 0;
}

