//CODING STAGE 1 & 2: Henri Berisha & Joseph Cittadino

//Matrix Standard Multiplication C = A*B; all matrices sizes randomly picked
//Minimum size 1x1, Maximum size 8x8....
// 1 <= rows <=8  1 <= cols <= 8
// Maximum value in a cell is 30, but it can be changed, change of type may be needed                                                                              |

// Matrices are declared as pointers and memory is allocated dynamically
// Need to consider matrices as 1D arrays


#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
// Driver program
int main(void){

    int MAX_VALUE = 30; //change this value to determine the maximum a value can be in the matrix.
    srand(time(0)); //Set the seed to generate different random numbers
    
    //Dimensions of matrix A and B, from 1-8. Minimum 1x1, Maximum 8x8
    int row_A = rand() % 8 + 1; 
    int col_A = rand() % 8 + 1;
    int row_B = col_A;
    int col_B = rand() % 8 + 1;

    //Allocating memory for A and B
    int* A = malloc((row_A * col_A) * sizeof(int));
    int* B = malloc((row_B * col_B) * sizeof(int));

    //Each value can be randomly generated from 1-MAX_VALUE for both matrices
    for (int i = 0; i < row_A * col_A; i++){
        A[i] = (rand() % MAX_VALUE) + 1;
    }

    for (int j = 0; j < row_B * col_B; j++){
        B[j] = (rand() % MAX_VALUE) + 1;
    }


    //Printing both matrices
    printf("\nMatrix A(%dx%d):\n", row_A, col_A);
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_A; j++)
            printf("%d ", A[i * col_A + j]);
        printf("\n");
    }

    printf("\nMatrix B(%dx%d):\n", row_B, col_B);
    for (int i = 0; i < row_B; i++) {
        for (int j = 0; j < col_B; j++)
            printf("%d ", B[i * col_B + j]);
        printf("\n");
    }

    //Calculating the product
    int* C = malloc((row_A * col_B) * sizeof(int));
    
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++) {
            int sum = 0;
            for (int k = 0; k < col_A; k++)
                sum += A[i * col_A + k] * B[k * col_B + j];
            C[i * col_B + j] = sum;
        }
    }

    //Printing the product C = A*B
    printf("\nMatrix C(%dx%d):\n", row_A, col_B);
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++)
            printf("%d ", C[i * col_B + j]);
        printf("\n");
    }
    printf("\n");

    //Deallocating the memory
    free(A);
    free(B);
    free(C);
    
    return 0;
}