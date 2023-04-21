/*
* @file Yusuf Kaya - BP3 Proje 1
* @description Girilen islem tipine gore zero paddingli ya da zero paddingsiz convolution matrisi hesaplayan program
* @assignment 1. Proje
* @date 18.12.2021
* @author Yusuf Kaya - yusuf_kaya@stu.fsm.edu.tr
*/

#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

int **operation1(int **matrix1, int size1, int **matrix2, int size2, int operationType);
void fillMatrix(int **matrix, int size,int seed);
void freeMatrix(int **matrix, int size);
void printMatrix(int **matrix, int size);
int **mallocMatrix(int size);
int **callocMatrix(int size);
int calcSize(int size1,int size2, int operationType);
void applyPadding(int** paddledMatrix, int paddledSize, int** matrix1, int size1,int size2, int operationType);
#endif