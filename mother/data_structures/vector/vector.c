#include "vector.h"

Vector getEmptyVector() {
    return (Vector) {
            NULL,
            0,
            0
    };
}

Vector createVector(size_t n) {
    Vector v = getEmptyVector();
    if (n > 0) {
        v.data = (int *) malloc(sizeof(int) * n);
        if (v.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v.size = 0;
        v.capacity = n;
    }

    return v;
}

void reserve(Vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity > v->capacity) {
        int *newData = (int *) realloc(v->data, sizeof(int) * newCapacity);
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

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    v->data = realloc(v->data, sizeof(int) * (v->capacity = v->size));
}

void deleteVector(Vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}