#ifndef MOTHER_SORT_H
#define MOTHER_SORT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// добавление значения x и обмен ребёнка и родителя в массиве (а) размера n
__attribute__((unused))void insertHeap(int *a, int *n, int x);

//
__attribute__((unused))bool hasLeftChild(int parentIndex, int n);

//
__attribute__((unused))bool hasRightChild(int parentIndex, int n);

//
__attribute__((unused))int getLeftChildIndex(int parentIndex);

//
__attribute__((unused))int getMinChildIndex(const int *a, int n, int parentIndex);

//
__attribute__((unused))void removeMinHeap(int *a, int *n);

//
__attribute__((unused))void heapSort(int *a, int n);

// проверка на сортировку в массиве (а) размера n
__attribute__((unused))bool isSorted(const int *a, const int n);

// рандомный обмен значений в массиве (а) размера n
__attribute__((unused))void shuffleArray(int *a, const int n);

// обезьянья сортировка массива (а) размера n
__attribute__((unused))int botSort(int *a, const int n);

// сортировка выбором массива (а) размера n
__attribute__((unused))void selectSort(int *a, const int n);

// сортировка вставкой массива (а) размера n
__attribute__((unused))void ctrlV(int *a, const int n);

// сортировка "пузырьком" массива (а) размера n
__attribute__((unused))void bubbleSort(int *a, const int n);

// сортировка расчёской массива (а) размера n
__attribute__((unused))void combSort(int *a, const int n);

// линейный поиск значения x в отсортированном массиве (а) размера n
__attribute__((unused))int lineSearchSort(const int *a, const int n, const int x);

// линейный поиск значения x в неотсортированном массиве (а) размера n
__attribute__((unused))int lineSearchUnSort(int *a, const int n, const int x);

// бинарный поиск значения x в отсортированном массиве (а) размера n
__attribute__((unused))int binarySearch(const int *a, const int n, const int x);

// бинарный поиск значения x в отсортированном массиве (а) размера n (right and left) (рекурсивно)
__attribute__((unused))int binarySearchRec_(const int *a, int x, int right, int left);

// функция-обёртка (бинарный поиск значения x в отсортированном массиве (а) размера n (right and left) (рекурсивно))
__attribute__((unused))int binarySearchRec(const int *a, int n, int x);

// возвращает "истина", если x > 20
__attribute__((unused))int isMore20(int x);

// бинарный поиск значения x в отсортированном массиве (а) размера n (2 вариант)
__attribute__((unused))int binarySearch2(const int *a, const int n, const int x);

// бинарный поиск по критерию f в массиве (а) размера n
__attribute__((unused))int binarySearchCriteria(const int *a, const int n, int (*f)(int));

#endif //MOTHER_SORT_H