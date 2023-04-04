#ifndef MOTHER_MATRIX_H
#define MOTHER_MATRIX_H

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

// матрица
typedef struct Matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} Matrix;

// позиция
typedef struct Position_ {
    int rowIndex;
    int colIndex;
} Position_;

// Размещает в динамической памяти матрицу размером nRows на nCols.
// Возвращает матрицу. Используется следующая схема размещения.
__attribute__((unused))Matrix getMemMatrix(int nRows, int nCols);

// Размещает в динамической памяти матрицу размером nCols на nRows.
// Возвращает матрицу. Используется следующая схема размещения.
__attribute__((unused))Matrix getMemMatrix_(int nCols, int nRows);

// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
// Возвращает указатель на нулевую матрицу
__attribute__((unused))Matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Освобождает память, выделенную под хранение матрицы m.
__attribute__((unused))void freeMemMatrix(Matrix m);

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц.
__attribute__((unused))void freeMemMatrices(Matrix *ms, int nMatrices);

// Ввод матрицы m.
__attribute__((unused))void inputMatrix(Matrix m);

// Ввод массива из nMatrices матриц, хранящейся по адресу ms.
__attribute__((unused))void inputMatrices(Matrix *ms, int nMatrices);

// Вывод матрицы m.
__attribute__((unused))void outputMatrix(Matrix m);

// Вывод массива из nMatrices матриц, хранящейся по адресу ms.
__attribute__((unused))void outputMatrices(Matrix *ms, int nMatrices);

// Обмен значениями a и b.
__attribute__((unused))void swapPointers(int **a, int **b);

// Обмен строк с порядковыми номерами i1 и i2 в матрице m.
__attribute__((unused))void swapRows(Matrix m, int i1, int i2);

// Обмен двух переменных a и b.
__attribute__((unused))void swap(int *a, int *b);

// Обмен колонок с порядковыми номерами j1 и j2 в матрице m.
__attribute__((unused))void swapColumns(Matrix m, int j1, int j2);

// Выполняет сортировку вставками строк матрицы m по не убыванию значения функции criteria применяемой для строк.
__attribute__((unused))void insertionSortRowsMatrixByRowCriteria(Matrix m, int (*criteria)(int const *, int));

// Выполняет сортировку выбором столбцов матрицы m по не убыванию значения функции criteria применяемой для столбцов.
__attribute__((unused))void selectionSortColsMatrixByColCriteria(Matrix m, int (*criteria)(int const *, int));

// Возвращает значение ’истина’, если матрица m является квадратной, ложь – в противном случае.
__attribute__((unused))bool isSquareMatrix(Matrix m);

// Возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
__attribute__((unused))bool areTwoMatricesEqual(Matrix m1, Matrix m2);

// Возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае.
__attribute__((unused))bool isEMatrix(Matrix m);

// Возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае.
__attribute__((unused))bool isSymmetricMatrix(Matrix m);

// Транспонирует квадратную матрицу m.
__attribute__((unused))void transposeSquareMatrix(Matrix m);

// Транспонирует матрицу m.
__attribute__((unused))void transposeMatrix(Matrix *m);

// Возвращает позицию минимального элемента матрицы m.
__attribute__((unused))Position_ getMinValuePos(Matrix m);

// Возвращает позицию максимального элемента матрицы m.
__attribute__((unused))Position_ getMaxValuePos(Matrix m);

// Возвращает матрицу размера nRows на nCols, построенную из элементов массива (a).
__attribute__((unused))Matrix createMatrixFromArray(const int *a, int nRows, int nCols);

// Возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
// в динамической памяти размерами nRows на nCols, построенных из элементов массива (a):
__attribute__((unused))Matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols);

#endif //MOTHER_MATRIX_H