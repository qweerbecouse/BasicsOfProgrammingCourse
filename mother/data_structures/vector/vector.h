#ifndef MOTHER_VECTOR_H
#define MOTHER_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//структура вектора
typedef struct Vector {
    int *data;    // указатель на элементы вектора
    int size;     // количество элементов в векторе (введенных)
    int capacity; // количество элементов в массиве под хранение элементов вектора
}Vector;

//увеличивает память для вектора
__attribute__((unused)) void addMemory(Vector *v);

//вставка значения x в вектор
__attribute__((unused)) void append(Vector *v, int x);

//проверка индекса
__attribute__((unused)) void checkIndex(Vector *v, int index);

//очищает вектор
__attribute__((unused)) void clear(Vector *v);

//вставка нескольких значений в массив (а) размера size
__attribute__((unused)) void extendC(Vector *v, const int *const a, int size);

//вставка нескольких значений в вектор
__attribute__((unused)) void extendV(Vector *v1, Vector *v2);

//возвращает пустой вектор
__attribute__((unused)) Vector getEmptyVector();

//возвращает вектор, заполненный массивом (а) размера size
__attribute__((unused)) Vector getVectorFromArray(const int *const a, int size);

//вставка в вектор на индекс index значение value с сохранением последовательности
__attribute__((unused))void insert(Vector *v, int index, int value);

//возвращает последний элемент вектора
__attribute__((unused)) int last(Vector *v);

//выводит вектор
__attribute__((unused)) void outputVector(Vector v);

//возвращает последний элемент вектора за его границей
__attribute__((unused)) int pop(Vector *v);

//перезапись значения на индексе index на значение value
__attribute__((unused)) void setItem(Vector *v, int index, int value);

//сортировка вектора
__attribute__((unused)) void sort(Vector *v);

//обмен двух переменных
__attribute__((unused)) void swap(int *a, int *b);

#endif //MOTHER_VECTOR_H
