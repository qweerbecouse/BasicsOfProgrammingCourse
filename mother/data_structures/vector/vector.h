#ifndef MOTHER_VECTOR_H
#define MOTHER_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// Структура вектора.
typedef struct Vector {
    int *data;       // указатель на элементы вектора.
    size_t size;     // количество элементов в векторе (введенных).
    size_t capacity; // количество элементов в массиве под хранение элементов вектора.
} Vector;

// Возвращает пустой вектор.
Vector getEmptyVector();

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

// Возвращает значение "истина", если вектор v пустой, иначе - "ложь".
bool isEmpty(Vector *v);

// Возвращает значение "истина", если вектор v полный, иначе - "ложь".
bool isFull(Vector *v);

// Возвращает i-ый элемент вектора v.
int getVectorValue(Vector *v, size_t i);

// Добавляет элемент x в конец вектора v.
void pushBack(Vector *v, int x);

// Удаляет последний элемент из вектора v.
void popBack(Vector *v);

// Возвращает указатель на index-ый элемент вектора v.
int *atVector(Vector *v, size_t index);

// Возвращает указатель на последний элемент вектора v.
int *back(Vector *v);

// Возвращает указатель на нулевой элемент вектора v.
int *front(Vector *v);

#endif //MOTHER_VECTOR_H