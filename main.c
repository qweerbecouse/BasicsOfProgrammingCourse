#include "mother/data_structures/vector/vector.h"

void test_atVector_notEmptyVector() {
    Vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);

    int *element = atVector(&v, 1);
    assert(*element == 20);

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    Vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);

    int *element = atVector(&v, v.size - 1);
    assert(*element == 20);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    Vector v = createVector(1);
    pushBack(&v, 10);

    int *element = back(&v);
    assert(*element == 10);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    Vector v = createVector(1);
    pushBack(&v, 10);

    int *element = front(&v);
    assert(*element == 10);

    deleteVector(&v);
}

void test() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}
