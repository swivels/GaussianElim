//
// Created by brian on 3/11/2025.
//
#include <iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H



class myMatrix {
public:
    int nrows;
    int ncols;
    double **matrix;
//constructors
    myMatrix(): nrows(0), ncols(0),matrix(nullptr){}
    myMatrix(size_t nrows, size_t ncols): nrows(nrows), ncols(ncols), matrix(nullptr) {initMatrix();}
    myMatrix& operator=(const myMatrix& other);
    myMatrix(const myMatrix& other);
    void printMatrix() const;
    void initMatrix() {
        deleteMatrix();
        matrix = new double*[nrows];
        for (size_t i = 0; i < nrows; ++i) {
            matrix[i] = new double[ncols];
        }
    }
    void deleteMatrix() {
        if (matrix != nullptr) {
            for (size_t i = 0; i < nrows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }
    ~myMatrix() {
        deleteMatrix();
    }
//functions
    void fillMatrix(const std::initializer_list<std::initializer_list<double>>& values);

    void swapRows(int row1,int row2);
    void GaussianElimination();


};


#endif //MATRIX_H
