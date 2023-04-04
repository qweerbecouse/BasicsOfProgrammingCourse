#ifndef LABA14_VECTORVOID_H
#define LABA14_VECTORVOID_H

#include <stdio.h>
#include <stdlib.h>

// Структура произвольного вектора.
typedef struct VectorVoid {
    void *data;             // указатель на нулевой элемент вектора
    size_t size;            // размер вектора
    size_t capacity;        // вместимость вектора
    size_t baseTypeSize;    // размер базового типа.
} VectorVoid;

// Возвращает пустой вектор произвольного типа baseTypeSize.
VectorVoid getEmptyVectorV(size_t baseTypeSize);

// Возвращает структуру-дескриптор вектор из n значений произвольного типа baseTypeSize.
VectorVoid createVectorV(size_t n, size_t baseTypeSize);

// Изменяет количество памяти, выделенное под хранение элементов вектора v на newCapacity.
void reserveV(VectorVoid *v, size_t newCapacity);

// Удаляет элементы из вектора v, но не освобождает выделенную память.
void clearV(VectorVoid *v);

// Освобождает память, выделенную под неиспользуемые элементы вектора v.
void shrinkToFitV(VectorVoid *v);

// Освобождает память, выделенную вектору v.
void deleteVectorV(VectorVoid *v);

#endif //LABA14_VECTORVOID_H