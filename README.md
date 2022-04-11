# STANDARD AND BLOCK MATRIX MULTIPLICATION


This repository contains two source code files for matrix multiplication

multiply.c
block_multiply.c


These files can be compiled and run independently from each other.
How to compile and run in WINDOWS OS
1) Open Command Prompt! [Can be found by typing cmd at the search bar in home page of WINDOWS]
2) Go to the same directory where the source files are located [use cd command, lookup cmd commands to change directory]
3) Make sure gcc compiler is installed by typing   gcc --version   if installed it will show the version, otherwise need to install
4) If installed
5) Type   gcc -o multiply multiply.c  and hit enter    
6) In the new line type  multiply   and hit enter
7) Type gcc -o block_multiply block_multiply.c
8) In the new line type  block_multiply   and hit enter


multiply.c 
-Program that performs standard matrix multiplication
-Takes two matrices A,B and multiplies them to store the results in matrix C
-Matrix Standard Multiplication C = A*B; all matrices sizes randomly picked
-Minimum size 1x1, Maximum size 8x8....
1 <= rows <=8  1 <= cols <= 8
-Maximum value in a cell is 30, but it can be changed, change of type may be needed
-Matrices are declared as pointers and memory is allocated dynamically
-Need to consider matrices as 1D arrays


block_multiply.c
-Matrix Block Multiplication C = A*B; all matrices sizes 24x24
-Block size for this application chosen to be 8x8 to maximize hardware usage
-"size_N" can be changed to a multiple of 8, default size should be 256
-if "size_N" is changed, change sizes of all matrices A,B,C to match the new value
-reference: https://csapp.cs.cmu.edu/public/waside/waside-blocking.pdf 
