#include <stdio.h>
#include <stdlib.h> 

int main() {
    FILE *fp; 

    fp = fopen("example.txt", "w"); 
    if (fp == NULL) {
        printf("Error opening file for write!\n");
        exit(1); 
    }
    fprintf(fp, "This is the first line.\n");
    fputs("This is the second line \n", fp);
    fclose(fp); 
     printf("Content written to example.txt\n");

    fp = fopen("example.txt", "a"); 
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        exit(1);
    }
    fprintf(fp, "This line is appended.\n");
    fclose(fp);

    printf("Content appended to example.txt\n");

    fp = fopen("example.txt", "r"); 
    if (fp == NULL) {
        printf("Error opening file for read!\n");
        exit(1);
    }
    printf("\nContent of example.txt (character by character):\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading (line by line)!\n");
        exit(1);
    }
    printf("\nContent of example.txt (line by line):\n");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);

    if (remove("example.txt") == 0) {
        printf("\nexample.txt deleted successfully.\n");
    } else {
        printf("\nError deleting example.txt.\n");
    }

    return 0;
}
