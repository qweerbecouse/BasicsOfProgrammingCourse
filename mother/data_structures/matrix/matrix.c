#include "matrix.h"

__attribute__((unused))Matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (Matrix) {values, nRows, nCols};
}

__attribute__((unused))Matrix getMemMatrix_(int nCols, int nRows) {
    int **values = (int **) malloc(sizeof(int *) * nCols);
    for (int i = 0; i < nCols; i++) {
        values[i] = (int *) malloc(sizeof(int) * nRows);
    }

    return (Matrix) {values, nCols, nRows};
}

__attribute__((unused))Matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    Matrix *pointerNullMatrix =
            (Matrix *) malloc(sizeof(Matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++) {
        pointerNullMatrix[i] = getMemMatrix(nRows, nCols);
    }

    return pointerNullMatrix;
}

__attribute__((unused))void freeMemMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        free(m.values[i]);
    }

    free(m.values);
}

__attribute__((unused))void freeMemMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(ms[i]);
    }

    free(ms);
}

__attribute__((unused))void inputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

__attribute__((unused))void inputMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

__attribute__((unused))void outputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }

        printf("\n");
    }
}

__attribute__((unused))void outputMatrices(Matrix *ms, int nMatrices) {
    for (int k = 0; k < nMatrices; k++) {
        for (int i = 0; i < ms->nRows; i++) {
            for (int j = 0; j < ms->nCols; j++) {
                printf("%d", ms->values[i][j]);
            }

            printf("\n");
        }

        printf("--------\n");
        ms++;
    }
}

__attribute__((unused))void swapPointers(int **a, int **b) {
    int *t = *a;
    *a = *b;
    *b = t;
}


__attribute__((unused))void swapRows(Matrix m, int i1, int i2) {
    assert(0 <= i1 && i1 < m.nRows);
    assert(0 <= i2 && i2 < m.nRows);

    swapPointers(&m.values[i1], &m.values[i2]);
}

__attribute__((unused))void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

__attribute__((unused))void swapColumns(Matrix m, int j1, int j2) {
    assert(0 <= j1 && j1 < m.nRows);
    assert(0 <= j2 && j2 < m.nRows);

    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

__attribute__((unused))void insertionSortRowsMatrixByRowCriteria(Matrix m, int (*criteria)(int const *, int)) {
    int *criteriaValues = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        criteriaValues[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 1; i < m.nRows; i++) {
        int t = criteriaValues[i];
        int j = i;
        while (j > 0 && criteriaValues[j - 1] > t) {
            criteriaValues[j] = criteriaValues[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }

        criteriaValues[j] = t;
    }

    free(criteriaValues);
}

__attribute__((unused))void selectionSortColsMatrixByColCriteria(Matrix m, int (*criteria)(int const *, int)) {
    int *criteriaValues = (int *) malloc(sizeof(int) * m.nCols);
    int *column = (int *) malloc(sizeof(int) * m.nRows);
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            column[i] = m.values[i][j];
        }

        criteriaValues[j] = criteria(column, m.nCols);
    }

    for (int i = 0; i < m.nCols; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (criteriaValues[j] < criteriaValues[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(&criteriaValues[i], &criteriaValues[minIndex]);
            swapColumns(m, i, minIndex);
        }
    }

    free(column);
    free(criteriaValues);
}

__attribute__((unused))bool isSquareMatrix(Matrix m) {
    return m.nRows == m.nCols ? true : false;
}

__attribute__((unused))bool areTwoMatricesEqual(Matrix m1, Matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        return false;
    }

    for (int i = 0; i < m1.nCols; i++) {
        if (memcmp(m1.values[i], m2.values[i],
                   sizeof(int) * m1.nCols) != 0) {
            return false;
        }
    }

    return true;
}

__attribute__((unused))bool isEMatrix(Matrix m) {
    if (m.nRows != m.nCols) {
        return false;
    }

    int n = m.nRows;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j) != m.values[i][j]) {
                return false;
            }
        }
    }

    return true;
}

__attribute__((unused))bool isSymmetricMatrix(Matrix m) {
    if (m.nRows != m.nCols) {
        return false;
    }

    for (int i = 1; i < m.nRows; i++) {
        for (int j = 0; j < m.nRows - 1; j++) {
            if (m.values[i][j] != m.values[j][i]) {
                return false;
            }
        }
    }

    return true;
}

__attribute__((unused))void transposeSquareMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i; j < m.nRows; j++) {
            swap(&m.values[i][j], &m.values[j][i]);
        }
    }
}

__attribute__((unused))void transposeMatrix(Matrix *m) {
    Matrix t = getMemMatrix_(m->nCols, m->nRows);
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            t.values[j][i] = m->values[i][j];
        }
    }

    freeMemMatrix(*m);
    *m = t;
}

__attribute__((unused))Position_ getMinValuePos(Matrix m) {
    Position_ minPos = {0, 0};
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] <
                m.values[minPos.rowIndex][minPos.colIndex]) {
                minPos = (Position_) {i, j};
            }
        }
    }

    return minPos;
}

__attribute__((unused))Position_ getMaxValuePos(Matrix m) {
    Position_ maxPos = {m.nRows - 1, m.nCols - 1};
    for (int i = m.nRows - 1; i >= 0; i--) {
        for (int j = m.nCols - 1; j >= 0; j--) {
            if (m.values[i][j] >
                m.values[maxPos.rowIndex][maxPos.colIndex]) {
                maxPos = (Position_) {i, j};
            }
        }
    }

    return maxPos;
}

__attribute__((unused))Matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    Matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            m.values[i][j] = a[k++];
        }
    }

    return m;
}

__attribute__((unused))Matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols) {
    Matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++) {
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                ms[k].values[i][j] = values[l++];
            }
        }
    }

    return ms;
}
