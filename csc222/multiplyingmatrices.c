#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrixwidth;
    int matrixheight;
    printf("Enter matrix width: ");
    scanf("%d", &matrixwidth);
    printf("Enter matrix height: ");
    scanf("%d", &matrixheight);
    int matrixa[matrixheight][matrixwidth];
    int matrixb[matrixheight][matrixwidth];
    for (int i = 0; i < matrixheight; i++) {
        for (int j = 0; j < matrixwidth; j++) {
            printf("Matrixa (%d,%d): ", j, i);
            scanf("%d", &matrixa[i][j]);
            printf("Matrixb (%d,%d): ", j, i);
            scanf("%d", &matrixb[i][j]);
        }
    }
    int result[matrixheight][matrixwidth];
    for (int i = 0; i < matrixheight; i++) {
        for (int j = 0; j < matrixwidth; j++) {
            int value = 0;
            for (int k = 0; k < matrixwidth; k++) {
                value = value + (matrixa[j][k] * matrixb[k][i]);
            }
            result[j][i] = value; //for some reason i had to swap the width and the height around here. I dont know why.
        }
    }
    
    printf("Result: \n");

    for (int i = 0; i < matrixheight; i++) {
        printf("|");
        for (int j = 0; j < matrixwidth; j++) {
            printf("%d|", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
