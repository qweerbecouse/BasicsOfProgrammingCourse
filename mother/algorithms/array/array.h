#ifndef MOTHER_ARRAY_H
#define MOTHER_ARRAY_H

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stddef.h>

//ввод массива a размера n
__attribute__((unused)) void inputArray_(int *a, size_t n);

//вывод массива a размера n
__attribute__((unused)) void outputArray_(const int *a, size_t n);

//добавление элемента value в конец массива a размера n
__attribute__((unused)) void append_(int *a, size_t *n, int value);

//вставка элемента со значением value в массив a размера n на позицию pos
__attribute__((unused)) void insert_(int *a, size_t *n, size_t pos, int value);

//удаление из массива a размера n элемента на позиции pos с сохранением порядка оставшихся элементов
__attribute__((unused)) void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

//удаление из массива a размера n элемента на позиции pos без сохранения порядка оставшихся элементов
//размер массива (а) уменьшается на единицу
__attribute__((unused)) void deleteByPosUnSaveOrder_(int *a, size_t *n, size_t pos);

//возвращает значение первого вхождения элемента x в массиве a размера n при его наличии, иначе - n
__attribute__((unused)) size_t linearSearch_(const int *a, size_t n, int x);

//возвращает значение ’истина’ если хотя бы один элемент массива a размера n соответствует функции-предикату predicate
//иначе - ’ложь’
__attribute__((unused)) int any_(const int *a, size_t n, int (*predicate )(int));

//возвращает значение ’истина’ если все элементы массива a размера n соответствует функции-предикату predicate
//иначе - ’ложь’
__attribute__((unused)) int all_(const int *a, size_t n, int (*predicate )(int));

//возвращает количество элементов массива a размера n удовлетворяющих функции-предикату predicate
__attribute__((unused)) int countIf_(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива a размера n все элементы, удовлетворяющие функции-предикату deletePredicate, записывает в n новый размер массива
__attribute__((unused)) void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

//применяет функцию predicate к элементам массива a размера size.
__attribute__((unused)) void forEach_(const int *source, int *dest, size_t n, const int (*predicate )(int));

//возвращает позицию вхождения элемента x в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
__attribute__((unused)) size_t binarySearch_(const int *a, size_t n, int x);

//возвращает позицию первого элемента равного или большего x в отсортированном массиве a размера n
//при отсутствии такого элемента возвращает n
__attribute__((unused)) size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x);

#endif //MOTHER_ARRAY_H
