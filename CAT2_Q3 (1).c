/*
Name:Simon Muthama Makenzi
Reg no:CT101/G/26522/25
Description:A c program that reads integers 
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Function to prompt user for 10 integers and save to "input.txt"
void writeInputFile() {
    FILE *fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        perror("Error opening input.txt for writing");
        return;
    }

    int num;
    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("✅ Numbers saved to input.txt\n\n");
}

// Function to read integers from "input.txt", compute sum and average, and write to "output.txt"
void processInputFile() {
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        perror("Error opening input.txt for reading");
        return;
    }

    FILE *outptr = fopen("output.txt", "w");
    if (outptr == NULL) {
        perror("Error opening output.txt for writing");
        fclose(fptr);
        return;
    }

    int num, sum = 0, count = 0;
    while (fscanf(fptr, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    double average = (count > 0) ? (double)sum / count : 0.0;
    fprintf(outptr, "Sum: %d\nAverage: %.2f\n", sum, average);

    fclose(fptr);
    fclose(outptr);
    printf("✅ Sum and average written to output.txt\n\n");
}

// Function to display contents of both files
void displayFiles() {
    FILE *fptr = fopen("input.txt", "r");
    FILE *outptr = fopen("output.txt", "r");

    if (fptr == NULL || outptr == NULL) {
        perror("Error opening files for display");
        if (fptr) fclose(fptr);
        if (outptr) fclose(outptr);
        return;
    }

    printf("📄 Contents of input.txt:\n");
    int num;
    int i = 1;
    while (fscanf(fptr, "%d", &num) == 1) {
        printf("Number %d: %d\n", i++, num);
    }

    printf("\n📄 Contents of output.txt:\n");
    char line[100];
    while (fgets(line, sizeof(line), outptr)) {
        printf("%s", line);
    }

    fclose(fptr);
    fclose(outptr);
    printf("\n✅ Display complete\n");
}

int main() {
    writeInputFile();
    processInputFile();
    displayFiles();
    return 0;
}