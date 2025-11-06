/*
Name:Simon Muthama Makenzi 
Reg no:CT101/G/26522/25
Description :scores with a nested for loop
*/
#include <stdio.h>

int main() {
    int scores1[2][2] = {
        {65, 92},
        {84, 72}
    };

    int scores2[2][2] = {
        {35, 70},
        {59, 67}
    };

    printf("Score 1:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", scores1[i][j]);
        }
        printf("\n");
    }

    printf("\nScore 2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", scores2[i][j]);
        }
        printf("\n");
    }

    return 0;
}