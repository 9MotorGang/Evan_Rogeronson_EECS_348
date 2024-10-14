#include <stdio.h>

//define constants for matrix sizes
#define SIZE1ROW 5
#define SIZE2ROW 5
#define SIZE1COL 5
#define SIZE2COL 5

//function to add 2 matrixes together
//input: 2 matrixes
//output: 1 matrix or an error
void addMatrix(int m1[SIZE1ROW][SIZE1COL], int m2[SIZE2ROW][SIZE2COL], int m3[SIZE2ROW][SIZE2COL]) {
    //ensure the matrixes are of compatable sizes
    if(SIZE1ROW != SIZE2ROW || SIZE1COL != SIZE2COL) {
        printf("Error: Invalid input.\n");
    }
    else {
        //iterate throw every element in the array using 2 nested for loops
        for(int i = 0; i < SIZE1ROW; i++) {
            for(int j = 0; j < SIZE1COL; j++) {
                //add the matrix items together
                m3[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }
}

//function to multiply 2 matrixes
//input: 2 matrixes
//output: 1 matrix or an error
void multiplyMatrices(int m1[SIZE1ROW][SIZE1COL], int m2[SIZE2ROW][SIZE2COL], int m3[SIZE1ROW][SIZE2COL]) {
    //ensure the matrixes are of compatable sizes for multiplication
    if(SIZE1COL != SIZE2ROW) {
        printf("Error: Invalid input.\n");
    }
    else {
        //iterate through the rows and columns of the result matrix
        for(int i = 0; i < SIZE1ROW; i++) {
            for(int j = 0; j < SIZE2COL; j++) {
                //initialize the result element to 0
                m3[i][j] = 0;
                //perform the multiplication for the current element
                for(int k = 0; k < SIZE1COL; k++) {
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
    }
}

//function to transpose a matrix
//input: 1 matrix
//output: the transposed matrix or an error
void transposeMatrix(int m1[SIZE1ROW][SIZE1COL], int m2[SIZE1COL][SIZE1ROW]) {
    //ensure the matrix is square for a transpose
    if(SIZE1ROW != SIZE1COL) {
        printf("Error: Invalid input.\n");
    }
    else {
        //iterate through the matrix to transpose rows into columns
        for(int i = 0; i < SIZE1ROW; i++) {
            for(int j = 0; j < SIZE1COL; j++) {
                m2[j][i] = m1[i][j];
            }
        }
    }
}

//function to print a matrix in a formatted way
void printMatrix(int matrix[SIZE1ROW][SIZE1COL]) {
    //find the maximum value to adjust spacing
    int max = 0;
    for (int i = 0; i < SIZE1ROW; i++) {
        for (int j = 0; j < SIZE1COL; j++) {
            //update max if a larger value is found
            if(matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    //print the matrix with appropriate spacing
    printf("\n");
    for (int i = 0; i < SIZE1ROW; i++) {
        printf("|");
        for (int j = 0; j < SIZE1COL; j++) {
            //print each element
            printf(" %d ", matrix[i][j]);
            //adjust spaces based on the max value
            for(int k = 10; k <= max; k = k*10) {
                if(max >= k ) {
                    if(matrix[i][j] < k ) {
                        printf(" ");
                    }
                }
            }
        }
        printf("|\n");
    }
}

//start main
int main() {
    //define and initialize matrix 1
    int m1[SIZE1ROW][SIZE1COL] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    //define and initialize matrix 2
    int m2[SIZE2ROW][SIZE2COL] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    //print the 2 intial matrixes
    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("\nMatrix 2:\n");
    printMatrix(m2);

    //define an array that will store the sum of 1 and 2
    int m3[SIZE2ROW][SIZE2COL];
    //call add matrix
    addMatrix(m1, m2, m3);
    //print the header
    printf("\nMatrix 1 + Matrix 2:\n");
    //print the result
    printMatrix(m3);

    //define an array for the result of multiplication
    int m4[SIZE1ROW][SIZE2COL];
    //call multiply matrix function
    multiplyMatrices(m1, m2, m4);
    //print the header
    printf("\nMatrix 1 times Matrix 2:\n");
    //print the multiplication result
    printMatrix(m4);

    //define an array for the transposed matrix
    int m5[SIZE1COL][SIZE1ROW];
    //call transpose matrix function
    transposeMatrix(m1, m5);
    //print the header
    printf("\nMatrix 1 transposed:\n");
    //print the transposed result
    printMatrix(m5);

    //end of main
    return 0;
}
