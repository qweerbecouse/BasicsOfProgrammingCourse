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
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}

bool isEmptyV(VectorVoid *v) {
    return v->size == 0;
}

bool isFullV(VectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(VectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(VectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);

    v->size++;
    if (v->size > v->capacity) {
        if (v->capacity == 0) {
            reserveV(v, 1);
        } else {
            reserveV(v, v->capacity * 2);
        }
    }
}

void pushBackV(VectorVoid *v, void *source) {
    if (isFullV(v)) {
        if (v->capacity == 0) {
            reserveV(v, 1);
        } else {
            reserveV(v, v->capacity * 2);
        }
    }
    char *destination = (char *) v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);

    v->size++;
}

void popBackV(VectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "error: attempting to pop back from empty vector\n");
        exit(1);
    }
    v->size--;
}