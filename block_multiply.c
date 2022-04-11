
// CODING STAGE 3: Henri Berisha & Joseph Cittadino

// Matrix Block Multiplication C = A*B; all matrices sizes 256x256
// Block size for this application chosen to be 8x8 to maximize hardware usage
// "size_N" can be changed to a multiple of 8, default size should be 24
// if "size_N" is changed, change sizes of all matrices A,B,C to match the new value
//reference: https://csapp.cs.cmu.edu/public/waside/waside-blocking.pdf


#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
// Driver program
int main(void){

    int MAX_VALUE = 30; //change this value to determine the maximum a value can be in the matrix.
    srand(time(0)); //Set the seed to generate different random numbers
    
    const int size_N = 24; //size of matrix NxN
    const int block_size = 8; //block size 8x8

    const int row_A = size_N; //setting the values for the loops
    const int col_A = size_N;
    const int row_B = size_N;
    const int col_B = size_N;

    //declaring the matrices that are to be multiplied
    //size for rows and cols for both A and B should be equal to "size_N" variable, otherwise incorrect results will ocurr
    int A[24][24], B[24][24];
    
    //Initialize and print both matrices
    printf("\nMatrix A(%dx%d):\n", row_A, col_A);
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_A; j++){
            A[i][j] = (rand() % MAX_VALUE) + 1; //set value
            printf("%d ", A[i][j]); //print value
        }
        printf("\n");
    }

    printf("\nMatrix B(%dx%d):\n", row_B, col_B);
    for (int i = 0; i < row_B; i++) {
        for (int j = 0; j < col_B; j++){
            B[i][j] = (rand() % MAX_VALUE) + 1; //set value 
            printf("%d ", B[i][j]); //print value
        }
        printf("\n");
    }

    //Declaring the product matrix C
    //size for rows and cols for C should be equal to "size_N" variable, otherwise incorrect results will ocurr
    long C[24][24];
    long sum;
    int en = block_size * (size_N/block_size); /* Amount that fits evenly into blocks */

    //Initializing C to all zeroes
    for (int i = 0; i < size_N; i++){
        for (int j = 0; j < size_N; j++)
            C[i][j] = 0;
    }

    //loops that calculate the product using block multiplication
    //Reference to the code in the paper published at the link below:
    //https://csapp.cs.cmu.edu/public/waside/waside-blocking.pdf
    for (int kk = 0; kk < en; kk += block_size) {
        for (int jj = 0; jj < en; jj += block_size) {
            for (int i = 0; i < size_N; i++) {
                for (int j = jj; j < jj + block_size; j++) {
                    sum = C[i][j];
                    for (int k = kk; k < kk + block_size; k++) {
                        sum += A[i][k]*B[k][j];
                    }
                    C[i][j] = sum;
                }
            }
        }
    }

    //Printing the product C = A*B
    printf("\nMatrix C(%dx%d):\n", row_A, col_B);
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}