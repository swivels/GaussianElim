#include "myMatrix.h"
#include <cfloat>
#include <cmath>

myMatrix& myMatrix::operator=(const myMatrix& other) {
    if (this == &other) {
        return *this; // handle self-assignment
    }
    // Clean up existing matrix
    deleteMatrix();
    // Copy dimensions
    nrows = other.nrows;
    ncols = other.ncols;
    // Allocate new matrix and copy values
    if (other.matrix != nullptr) {
        matrix = new double*[nrows];
        for (size_t i = 0; i < nrows; ++i) {
            matrix[i] = new double[ncols];
            for (size_t j = 0; j < ncols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    } else {
        matrix = nullptr;
    }

    return *this;
}
myMatrix::myMatrix(const myMatrix& other) : nrows(other.nrows), ncols(other.ncols), matrix(nullptr) {
    if (other.matrix != nullptr) {
        matrix = new double*[nrows];
        for (size_t i = 0; i < nrows; ++i) {
            matrix[i] = new double[ncols];
            for (size_t j = 0; j < ncols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
}
void myMatrix::fillMatrix(const initializer_list<initializer_list<double>>& values) {
    size_t i = 0;
    for (const auto& row : values) {
        size_t j = 0;
        for (const auto& val : row) {
            if (i < nrows && j < ncols) {
                matrix[i][j] = val;
            }
            ++j;
        }
        ++i;
    }
}
void myMatrix::printMatrix() const {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void myMatrix::swapRows(int row1, int row2) {
    double *temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

void myMatrix::GaussianElimination() {
    double max,curr;
    int maxInd;
    for (int diag = 0; diag < nrows; diag++) { //This is the column we are working, to get a single 1.0 where it crosses the diagonal
        max = -DBL_MAX;
        maxInd = -1;
        for (int rpart = diag; rpart< nrows; rpart++) {
            curr = fabs(matrix[rpart][diag]);
            if (curr>max) { //find row index of entry in this column that is biggest but below the diagonal
                max = curr;
                maxInd = rpart;
            }
        }
        if (maxInd != diag) { //swap it there
            swapRows(maxInd,diag);
        }
        double mdd = matrix[diag][diag];
        if (mdd == 0.0) {
            printf("Matrix is linearly dependent.");
            exit(1);
        }
        //Now scale row so diagonal position in row has a value of 1
        for (int cols = diag; cols < ncols; cols++) {
            matrix[diag][cols] *= 1.0/mdd;
        }
        //scale and subtract from other rows so that all other values in the column are 0
        for (int row = 0; row < nrows; row++) {
            if (row != diag) {
                double mrd = matrix[row][diag];
                for (int cpart = diag; cpart< ncols; cpart++) {
                    matrix[row][cpart] -= mrd*matrix[diag][cpart];
                }
            }
        }
    }
    return;
}