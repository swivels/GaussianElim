#include <iostream>
#include <vector>
#include "myMatrix.h"


int main() {
    myMatrix A(3, 7); // 3x6 matrix with doubles
    A.fillMatrix({{1.0, 2.0, 3.0, 1.0, 0.0, 0.0, 5.0},
                        {4.0, 5.0, 6.0, 0.0, 1.0, 0.0,-2.0},
                        {7.0, 8.0, 10.0, 0.0, 0.0, 1.0,7.0}});

    cout<<"input with identity myMatrix augmenting coefficients on the right"<<endl;
    cout<<"Ax = I"<<endl;//the identity matrix will be turned into a A^-1 by row operations. A^-1 contains the row operations needed to reach the identity
    A.printMatrix();
    A.GaussianElimination();
    A.printMatrix();
    cout<<"Example 2: solve for specific B vector:"<<endl;
    myMatrix B(3,4);
    B.fillMatrix({{1.0, 2.0, 3.0, 5.0},
                        {4.0, 5.0, 6.0, -2.0},
                        {7.0, 8.0, 10.0, 7.0}});
    B.printMatrix();
    B.GaussianElimination();
    B.printMatrix();
}
