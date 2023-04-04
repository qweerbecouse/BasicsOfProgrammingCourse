#include <stdio.h>

typedef struct VectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} VectorVoid;

int main() {
    VectorVoid v = {NULL, 0, 0, sizeof(int)};

    return 0;
}
