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

int **operation1(int **matrix1, int size1, int **matrix2, int size2, int operationType)
{
    int G = size1;
    int F = size2;
    int D = operationType; // if operationType = 0 -> D = 0

    // print values for better understanding of formulas
    printf("---------------------------\n");
    if (operationType == 1)
    {
        D = (F - 1) / 2;
        printf("D = (%d - 1) / 2\n", F);
    }
    printf("G = %d, F = %d, D = %d\n", G, F, D);
    int newSize = calcSize(size1,size2,operationType);
    printf("\nNEW SIZE = (%d - %d) + (2 * %d) + 1 = %d\n", G, F, D, newSize);
    printf("---------------------------\n\n");

    int **newMatrix = mallocMatrix(newSize);
    int sum = 0;
    for (int n = 0; n < newSize; n++) // fill resultMatrix with summations
    {
        for (int k = 0; k < newSize; k++)
        {
            sum = 0;
            for (int i = n; i < n + size2; i++) // multiply and add values element-wise
            {
                for (int j = k; j < k + size2; j++)
                {
                    sum += matrix1[i][j] * matrix2[i - n][j - k];
                }
            }
            newMatrix[n][k] = sum;
        }
    }

    return newMatrix;
}
int calcSize(int size1, int size2, int operationType){
    int G = size1;
    int F = size2;
    int D = operationType; // if operationType = 0 -> D = 0
    if (operationType == 1)
    {
        D = (F - 1) / 2;
    }
    return (((G - F) + (2 * D)) / 1) + 1;
}
void fillMatrix(int **matrix, int size, int seed)
{
    srand(seed);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = (int)(rand() % 10 + 1); // [1,10]
        }
    }
}

void freeMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%4d  ", matrix[i][j]);
        }
        puts("\n");
    }
}

int **mallocMatrix(int size)
{
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}
int **callocMatrix(int size)
{
    int **matrix = calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        matrix[i] = calloc(size, sizeof(int));
    }
    return matrix;
}
void applyPadding(int** paddledMatrix, int paddledSize, int** matrix1, int size1,int size2, int operationType){
    if (operationType == 1) // zero padding
    {
        if (size2 == 3)
        {
            // paddledMatrix = callocMatrix(paddledSize); // 1 layer of padding
            for (int i = 1; i < paddledSize - 1; i++)
            {
                for (int j = 1; j < paddledSize - 1; j++)
                {
                    paddledMatrix[i][j] = matrix1[i - 1][j - 1];
                }
            }
        }
        else if (size2 == 5)
        {
            // paddledMatrix = callocMatrix(paddledSize); // 2 layer of padding
            for (int i = 2; i < paddledSize - 2; i++)
            {
                for (int j = 2; j < paddledSize - 2; j++)
                {
                    paddledMatrix[i][j] = matrix1[i - 2][j - 2];
                }
            }
        }
    }
}