#include "mother/data_structures/vector/vector.h"
#include "mother/data_structures/vector/vectorVoid.h"

void test_getEmptyVector() {
    Vector v = getEmptyVector();

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
}

void test_createVector_emptyVector() {
    Vector v = createVector(5);

    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 5);


    deleteVector(&v);
}

void test_reserve_notEmptyVector() {
    Vector v = createVector(5);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    v.size = 3;

    reserve(&v, 10);

    assert(v.data != NULL);
    assert(v.size == 3);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_isEmpty() {
    Vector v = createVector(5);
    v.size = 3;

    assert(!isEmpty(&v));

    deleteVector(&v);
}

void test_isFull() {
    Vector v1 = createVector(0);

    assert(isFull(&v1));

    Vector v2 = createVector(5);
    v2.size = 3;

    assert(!isFull(&v2));

    deleteVector(&v2);
}

void test_getVectorValue_notEmptyVector() {
    Vector v = createVector(5);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    v.size = 3;

    int result1 = getVectorValue(&v, 0);
    int result2 = getVectorValue(&v, 2);

    assert(result1 == 1);
    assert(result2 == 3);

    deleteVector(&v);
}

void test_pushBack_notEmptyVector() {
    Vector v = createVector(2);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(*atVector(&v, 0) == 1);
    assert(*atVector(&v, 1) == 2);
    assert(*atVector(&v, 2) == 3);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    Vector v = createVector(3);

    v.data[0] = 1;
    v.size = 1;

    popBack(&v);

    assert(v.size == 0);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    Vector v = createVector(5);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    v.size = 3;

    int *value1 = atVector(&v, 0);
    int *value2 = atVector(&v, 2);

    assert(*value1 == 1);
    assert(*value2 == 3);

    deleteVector(&v);
}

void test_back() {
    Vector v = createVector(3);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(*back(&v) == 3);

    deleteVector(&v);
}

void test_front() {
    Vector v = createVector(3);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(*front(&v) == 1);

    deleteVector(&v);
}

void test_getEmptyVectorV_int() {
    VectorVoid v = getEmptyVectorV(sizeof(int));

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_createVectorV_notEmptyVector() {
    VectorVoid v = createVectorV(5, sizeof(double));

    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 5);
    assert(v.baseTypeSize == sizeof(double));

    deleteVectorV(&v);
}

void test_reserveV_notEmptyVector() {
    VectorVoid v = createVectorV(5, sizeof(int));

    reserveV(&v, 10);

    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 10);
    assert(v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_clearV_notEmptyVector() {
    VectorVoid v = createVectorV(5, sizeof(int));

    pushBackV(&v, &(int) {1});
    pushBackV(&v, &(int) {2});
    pushBackV(&v, &(int) {3});

    clearV(&v);

    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 5);
    assert(v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_shrinkToFitV_notEmptyVector() {
    VectorVoid v = createVectorV(5, sizeof(int));

    pushBackV(&v, &(int) {1});
    pushBackV(&v, &(int) {2});
    pushBackV(&v, &(int) {3});

    reserveV(&v, 10);
    shrinkToFitV(&v);

    assert(v.data != NULL);
    assert(v.size == 3);
    assert(v.capacity == 3);
    assert(v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_deleteVectorV_notEmptyVector() {
    VectorVoid v = createVectorV(5, sizeof(int));

    pushBackV(&v, &(int) {1});
    pushBackV(&v, &(int) {2});
    pushBackV(&v, &(int) {3});

    deleteVectorV(&v);

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.baseTypeSize == 0);

    deleteVectorV(&v);
}

void test_isEmptyV_notEmptyVector() {
    VectorVoid v = createVectorV(5, sizeof(int));

    assert(isEmptyV(&v));

    pushBackV(&v, &(int) {1});

    assert(!isEmptyV(&v));

    deleteVectorV(&v);
}

void test_isFullV_notEmptyVector() {
    VectorVoid v = createVectorV(3, sizeof(int));

    pushBackV(&v, &(int) {1});
    pushBackV(&v, &(int) {2});
    pushBackV(&v, &(int) {3});

    assert(isFullV(&v));

    deleteVectorV(&v);
}

void test_getVectorValueV_notEmptyVector() {
    VectorVoid v = createVectorV(5, sizeof(int));

    int values[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        setVectorValueV(&v, i, &values[i]);
    }

    int result1, result2;
    getVectorValueV(&v, 2, &result1);
    getVectorValueV(&v, 4, &result2);

    assert(result1 == 3);
    assert(result2 == 5);

    deleteVectorV(&v);
}

void test_setVectorValueV_notEmptyVector() {
    VectorVoid v = createVectorV(3, sizeof(char));

    char value1 = 'a';
    char value2 = 'b';

    setVectorValueV(&v, 0, &value1);
    setVectorValueV(&v, 1, &value2);

    assert(v.size == 2);

    char result1, result2;
    getVectorValueV(&v, 0, &result1);
    getVectorValueV(&v, 1, &result2);

    assert(result1 == 'a');
    assert(result2 == 'b');

    deleteVectorV(&v);
}

void test_pushBackV_notEmptyVector() {
    VectorVoid v = createVectorV(2, sizeof(char));

    char value1 = 'a';
    char value2 = 'b';
    pushBackV(&v, &value1);
    pushBackV(&v, &value2);

    char value3 = 'c';
    pushBackV(&v, &value3);

    assert(v.size == 3);
    assert(value3 == 'c');

    deleteVectorV(&v);
}

void test_popBackV_emptyVector() {
    VectorVoid v = createVectorV(3, sizeof(float));

    float value1 = 1.2;
    float value2 = 2.3;
    float value3 = 3.4;

    pushBackV(&v, &value1);
    pushBackV(&v, &value2);
    pushBackV(&v, &value3);

    popBackV(&v);

    assert(v.size == 2);
    assert(value2 - 2.3 < 0.0001);

    deleteVectorV(&v);
}

void test_vector() {
    test_getEmptyVector();
    test_createVector_emptyVector();
    test_reserve_notEmptyVector();
    test_isEmpty();
    test_isFull();
    test_getVectorValue_notEmptyVector();
    test_pushBack_notEmptyVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_back();
    test_front();
}

void test_vectorVoid() {
    test_getEmptyVectorV_int();
    test_createVectorV_notEmptyVector();
    test_reserveV_notEmptyVector();
    test_shrinkToFitV_notEmptyVector();
    test_clearV_notEmptyVector();
    test_deleteVectorV_notEmptyVector();
    test_isEmptyV_notEmptyVector();
    test_isFullV_notEmptyVector();
    test_getVectorValueV_notEmptyVector();
    test_setVectorValueV_notEmptyVector();
    test_popBackV_emptyVector();
    test_pushBackV_notEmptyVector();
}

void test() {
    test_vector();
    test_vectorVoid();
}

int main() {
    test();
}