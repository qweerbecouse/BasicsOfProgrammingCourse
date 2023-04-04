#include "sort.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

__attribute__((unused))void insertHeap(int *a, int *n, int x) {
    a[(*n)++] = x;
    int childIndex = *n - 1;
    int parentIndex = (childIndex - 1) / 2;
    while (a[childIndex] < a[parentIndex] && childIndex != 0) {
        swap(&a[childIndex], &a[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

__attribute__((unused))bool hasLeftChild(int parentIndex, int n) {
    return 2 * parentIndex + 1 < n;
}

__attribute__((unused))bool hasRightChild(int parentIndex, int n) {
    return 2 * parentIndex + 2 < n;
}

__attribute__((unused))int getLeftChildIndex(int parentIndex) {
    return 2 * parentIndex + 1;
}

__attribute__((unused))int getMinChildIndex(const int *a, int n, int parentIndex) {
    int minChildIndex = getLeftChildIndex(parentIndex);
    int rightChildIndex = minChildIndex + 1;
    if (hasRightChild(parentIndex, n)) {
        if (a[rightChildIndex] < a[minChildIndex]) {
            minChildIndex = rightChildIndex;
        }
    }

    return minChildIndex;
}

__attribute__((unused))void removeMinHeap(int *a, int *n) {
    *n -= 1;
    swap(&a[0], &a[*n]);
    int parentIndex = 0;
    while (hasLeftChild(parentIndex, *n)) {
        int minChildIndex = getMinChildIndex(a, *n, parentIndex);
        if (a[minChildIndex] < a[parentIndex]) {
            swap(&a[minChildIndex], &a[parentIndex]);
            parentIndex = minChildIndex;
        } else {
            break;
        }
    }
}

__attribute__((unused))void heapSort(int *a, int n) {
    int heapSize = 0;
    while (heapSize != n) {
        insertHeap(a, &heapSize, a[heapSize]);
    }

    while (heapSize) {
        removeMinHeap(a, &heapSize);
    }
}

__attribute__((unused))bool isSorted(const int *a, const int n) {
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }

    return true;
}

__attribute__((unused))void shuffleArray(int * const a, const int n) {
    for (int i = 0; i < n; i++) {
        swap(&a[i], &a[rand() % n]);
    }
}

__attribute__((unused))int botSort(int *a, const int n) {
    int count = 0;

    while (!isSorted(a, n)) {
        shuffleArray(a, n);
        count++;
    }

    return count;
}

__attribute__((unused))void selectSort(int *a, const int n) {
    for (int i = 0; i < n - 1; i++) {
        int minPosition = i;

        for (int j = i + 1; j < n; j++) {
            if (a[minPosition] > a[j]) {
                minPosition = j;
            }
        }

        swap(&a[minPosition], &a[i]);
    }
}

__attribute__((unused))void ctrlV(int *a, const int n) {
    for (int i = 1; i < n; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }

        a[j] = t;
    }
}

__attribute__((unused))void bubbleSort(int *a, const int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
            }
        }
    }
}

__attribute__((unused))void combSort(int *a, const int n) {
    int step = n;
    int swapped = 0;

    while (step > 1 || swapped) {
        if (step > 1) {
            step /= 1.24733;
        }

        swapped = 0;

        for (int i = 0, j = i + step; j < n; i++, j++) {
            if (a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
                swapped = 1;
            }
        }
    }
}

__attribute__((unused))int lineSearchSort(const int *a, const int n, const int x) {
    int i = 0;

    while (i < n && a[i] != x) {
        i++;
    }

    return a[i] == x ? i : -1;
}

__attribute__((unused))int lineSearchUnSort(int *a, const int n, const int x) {
    a[n] = x;

    int i = 0;
    while (a[i] != x) {
        i++;
    }

    return i == n ? -1 : i;
}

__attribute__((unused))int binarySearch(const int *a, const int n, const int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;

        if (a[middle] < x) {
            left = middle + 1;
        } else if (a[middle] > x) {
            right = middle - 1;
        } else {
            return middle;
        }
    }

    return -1;
}

__attribute__((unused))int binarySearchRec_(const int *a, int x, int right, int left) {
    if (left > right) {
        return -1;
    } else {
        int middle = (left + right) / 2;

        if (a[middle] == x) {
            return middle;
        } else if (a[middle] < x) {
            return binarySearchRec_(a, x, right, middle + 1);
        } else {
            return binarySearchRec_(a, x, middle - 1, left);
        }
    }
}

__attribute__((unused))int binarySearchRec(const int *a, int n, int x) {
    return binarySearchRec_(a, x, n - 1, 0);
}

__attribute__((unused))int isMore20(int x) {
    return x > 20;
}

__attribute__((unused))int binarySearch2(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;

        if (a[middle] < x) {
            left = middle;
        } else {
            right = middle;
        }
    }

    return right;
}

__attribute__((unused))int binarySearchCriteria(const int *a, const int n, int (*f)(int)) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (right + left) / 2;

        if (f(a[middle])) {
            right = middle;
        } else {
            left = middle;
        }
    }

    return right;
}