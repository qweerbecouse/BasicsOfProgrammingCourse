#ifndef MOTHER_VECTOR_H
#define MOTHER_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//структура вектора
typedef struct Vector {
    int *data;       // указатель на элементы вектора
    size_t size;     // количество элементов в векторе (введенных)
    size_t capacity; // количество элементов в массиве под хранение элементов вектора
} Vector;

// Возвращает структуру-дескриптор вектор из n значений.
Vector createVector(size_t n);

// Изменяет количество памяти, выделенное под хранение элементов вектора v на newCapacity.
void reserve(Vector *v, size_t newCapacity);

// Удаляет элементы из вектора v, но не освобождает выделенную память.
void clear(Vector *v);

// Освобождает память, выделенную под неиспользуемые элементы вектора v.
void shrinkToFit(Vector *v);

// Освобождает память, выделенную вектору v.
void deleteVector(Vector *v);

#endif //MOTHER_VECTOR_H
