#ifndef MOTHER_STRING__H
#define MOTHER_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <memory.h>

// Возвращает количество символов в строке, начиная с begin (не
// считая ноль-символ).
__attribute__((unused))size_t strlen_(const char *begin);

// Возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end. Если символ не найден, возвращается значение end.
__attribute__((unused))char *find(char *begin, char *end, int ch);

// Возвращает указатель на первый символ, отличный от пробельных, расположенный на
// ленте памяти, начиная с begin и заканчивая ноль-символом. Если символ не найден,
// возвращается адрес первого ноль-символа.
__attribute__((unused))char *findNonSpace(char *begin);

// Возвращает указатель на первый пробельный символ, расположенный на ленте памяти
// начиная с адреса begin или на первый ноль-символ.
__attribute__((unused))char *findSpace(char *begin);

// Возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin (последний символ
// строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки).
// Если символ не найден, возвращается адрес rend.
__attribute__((unused))char *findNonSpaceReverse(char *rbegin, const char *rend);

// Возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
__attribute__((unused))char *findSpaceReverse(char *rbegin, const char *rend);

// Возвращает отрицательное значение, если s1 располагается до s2
// в лексикографическом порядке (как в словаре), значение 0, если s1 и s2
// равны, иначе – положительное значение.
__attribute__((unused))int strcmp_(const char *s1, const char *s2);

// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса
// beginSource до endSource47 Возвращает указатель на следующий свободный фрагмент
// памяти в destination.
__attribute__((unused))char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная
// с beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
// Функция возвращает указатель на следующий свободный для записи фрагмент в
//памяти.
__attribute__((unused))char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// Записывает по адресу beginDestination элементы из фрагмента памяти начиная
// с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончании работы функции.
__attribute__((unused))char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

// Тесты для строк.
__attribute__((unused))void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

#endif //MOTHER_STRING__H
