#include <stdio.h>
int main() {
    FILE *fptr;
    // Create or open file for writing
    fptr = fopen("example.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    // Write data to file
    fputs("Hello, World!\n", fptr);
    // Close the file
    fclose(fptr);
    printf("File created successfully.\n");
    return 0;
}

