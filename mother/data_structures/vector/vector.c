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

bool isEmpty(Vector *v) {
    return v->size == 0;
}

bool isFull(Vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(Vector *v, size_t i) {
    return v->data[i];
}

void pushBack(Vector *v, int x) {
    if (isFull(v)) {
        if (v->capacity == 0) {
            reserve(v, 1);
        } else {
            reserve(v, v->capacity * 2);
        }
    }
    v->data[v->size++] = x;
}

void popBack(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "error: attempting to pop back from empty vector\n");
        exit(1);
    }
    v->size--;
}

int *atVector(Vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "indexError: a[%zu] is not exists\n", index);
        exit(1);
    }

    return &(v->data[index]);
}

int *back(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "error: vector is empty\n");
        exit(1);
    }

    return &(v->data[v->size - 1]);
}

int *front(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "error: vector is empty\n");
        exit(1);
    }

    return &(v->data[0]);
}