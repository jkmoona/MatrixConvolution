/*
* @file Yusuf Kaya - BP3 Proje 1
* @description Girilen islem tipine gore zero paddingli ya da zero paddingsiz convolution matrisi hesaplayan program
* @assignment 1. Proje
* @date 18.12.2021
* @author Yusuf Kaya - yusuf_kaya@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrixoperations.h"

int main(int argc, char *argv[])
{
    // input error handling
    if (argc == 1)
    {
        puts("No arguments!");
        exit(0);
    }
    else if ((argc > 5) || (argc < 5))
    {
        puts("Required arguments : size1, size2, operation_type, seed");
        exit(0);
    }
    int size1 = atoi(argv[1]), size2 = atoi(argv[2]), seed = atoi(argv[4]);
    int operationType;
    if (argv[3][0] == '0')
    {
        operationType = 0;
    }
    else if (argv[3][0] == '1')
    {
        operationType = 1;
    }
    else
    {
        puts("Operation type must be either 0 or 1 !");
        exit(0);
    }

    if (size1 % 2 == 0 || size2 % 2 == 0 || size1 < 3 || size2 < 3)
    {
        puts("Matrix sizes must be like: 3x3, 5x5, 7x7, 11x11, ...");
        exit(0);
    }
    if (!(size2 == 3 || size2 == 5))
    {
        puts("Matrix2 must be either 3x3 or 5x5!");
        exit(0);
    }
    if ((size2 > size1) && operationType == 0)
    { // kernel cannot be greater than matrix1 without zero padding
        puts("Size of matrix2 cannot be greater than size of matrix1 when operation type is 0!");
        exit(0);
    }

    int **matrix1 = mallocMatrix(size1);
    int **matrix2 = mallocMatrix(size2);
    fillMatrix(matrix1, size1, seed);
    fillMatrix(matrix2, size2, seed);

    int **paddledMatrix;
    int paddledSize;
    if (operationType == 1)
    {
        if (size2 == 3)
        {
            paddledSize = size1 + 2; // 1 layer of zero padding
        }
        else
        {
            paddledSize = size1 + 4; // 2 layer of zero padding
        }
        paddledMatrix = callocMatrix(paddledSize);
        applyPadding(paddledMatrix, paddledSize,matrix1, size1, size2, operationType);
    }

    puts("| First Matrix |\n");
    if (operationType == 1)
    {
        printMatrix(paddledMatrix, paddledSize);
    }
    else
    {
        printMatrix(matrix1, size1);
    }
    printf("---------------------------\n");
    puts("| Second Matrix |\n");
    printMatrix(matrix2, size2);
    int **resultMatrix;
    if (operationType == 1)
    {
        resultMatrix = operation1(paddledMatrix, size1, matrix2, size2, operationType);
    }
    else
    {
        resultMatrix = operation1(matrix1, size1, matrix2, size2, operationType);
    }
    int newSize = calcSize(size1, size2, operationType);
    puts("| Result Matrix |\n");
    printMatrix(resultMatrix, newSize);
    printf("---------------------------\n");

    // de-allocation
    if (operationType == 1)
    {
        freeMatrix(paddledMatrix, paddledSize);
    }
    freeMatrix(resultMatrix, newSize);
    freeMatrix(matrix1, size1);
    freeMatrix(matrix2, size2);
}
