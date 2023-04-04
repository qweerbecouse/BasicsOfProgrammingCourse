#include "algorithms.h"

__attribute__((unused)) void universalSwap(void *a, void *b, size_t size) {
    char *pa = (char *) a;
    char *pb = (char *) b;
    for (size_t i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}