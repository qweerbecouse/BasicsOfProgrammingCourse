#include "vector.h"

__attribute__((unused)) Vector getEmptyVector() {
    return (Vector) {
            NULL,
            0,
            0
    };
}

__attribute__((unused)) Vector getVectorFromArray(const int *const a, int size) {
    Vector v;
    v.data = (int *) malloc(sizeof(int) * size);
    memcpy(v.data, a, sizeof(int) * size);
    v.size = size;
    v.capacity = size;
    return v;
}

__attribute__((unused)) void clear(Vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

__attribute__((unused)) void outputVector(Vector v) {
    printf("[");
    for (int i = 0; i < v.size - 1; i++)
        printf("%d, ", v.data[i]);
    if (v.size != 0)
        printf("%d", v.data[v.size - 1]);
    printf("]");
}

__attribute__((unused)) void addMemory(Vector *v) {
    int newCapacity = v->capacity == 0 ? 1 : v->capacity * 2;
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    v->capacity = newCapacity;
}

__attribute__((unused)) void append(Vector *v, int x) {
    if (v->size == v->capacity)
        addMemory(v);
    v->data[v->size] = x;
    v->size += 1;
}

__attribute__((unused)) void extendC(Vector *v, const int *const a, int size) {
    for (int i = 0; i < size; i++)
        append(v, a[i]);
}

__attribute__((unused)) void extendV(Vector *v1, Vector *v2) {
    for (int i = 0; i < v2->size; i++)
        append(v1, v2->data[i]);
}

__attribute__((unused)) int last(Vector *v) {
    return v->data[v->size - 1];
}

__attribute__((unused)) int pop(Vector *v) {
    assert(v->size != 0);
    int el = last(v);
    v->size--;
    return el;
}

__attribute__((unused)) void checkIndex(Vector *v, int index) {
    assert(index >= 0 && index < v->size);
}

__attribute__((unused)) void setItem(Vector *v, int index, int value) {
    checkIndex(v, index);
    v->data[index] = value;
}

__attribute__((unused)) void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

__attribute__((unused)) void sort(Vector *v) {
    for (int i = 0; i < v->size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < v->size; j++)
            if (v->data[j] < v->data[minIndex])
                minIndex = j;
        if (minIndex != i)
            swap(&v->data[i], &v->data[minIndex]);
    }
}

__attribute__((unused)) void insert(Vector *v, int index, int value) {
    checkIndex(v, index);
    append(v, 0);
    for (int i = v->size - 2; i >= index; i--)
        setItem(v, i + 1, v->data[i]);
    setItem(v, index, value);
}