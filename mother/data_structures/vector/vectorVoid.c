#include "vectorVoid.h"

VectorVoid getEmptyVectorV(size_t baseTypeSize) {
    return (VectorVoid) {
            NULL,
            0,
            0,
            baseTypeSize
    };
}

VectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    VectorVoid v = getEmptyVectorV(baseTypeSize);
    if (n > 0) {
        v.data = malloc(baseTypeSize * n);
        if (v.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v.size = 0;
        v.capacity = n;
        v.baseTypeSize = baseTypeSize;
    }

    return v;
}

void reserveV(VectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity > v->capacity) {
        void *newData = realloc(v->data, v->baseTypeSize * newCapacity);
        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = newData;
    }

    if (newCapacity < v->size) {
        v->size = newCapacity;
    }
    v->capacity = newCapacity;
}

void clearV(VectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(VectorVoid *v) {
    v->data = realloc(v->data, v->baseTypeSize * (v->capacity = v->size));
}

void deleteVectorV(VectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}