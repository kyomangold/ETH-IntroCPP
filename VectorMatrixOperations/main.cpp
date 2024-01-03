//
//  main.cpp
//  Vector Matrix Operations
//
//  Created by Kyo Mangold on 23.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//
//
#include <iostream>



// POST: vector filled with values from std input
void input_vector(int (&res)[3])
{
    for (int i=0; i != 3; ++i) {
        std::cin >> res[i];
    }
}

// POST: matrix output to std output
void output_vector(const int (&res)[3])
{
    for (int i=0; i != 3; ++i) {
        std::cout << res[i] << "\n";
    }
}


// POST: matrix filled with values from std input
void input_matrix(int (&matrix)[3][3])
{
    for (int row = 0; row != 3; ++row) {
        for (int col = 0; col != 3; ++col)
            std::cin >> matrix[row][col];
    }
}

// POST: matrix output to std output
void output_matrix(const int (&matrix)[3][3])
{
    for (int row = 0; row != 3; ++row) {
        for (int col = 0; col != 3; ++col)
            std::cout << matrix[row][col] << " ";
        std::cout << "\n";
    }
}

// POST: result contains the cross product of left and right
void cross_product(int (&res)[3], const int (&left)[3], const int (&right)[3])
{
    res[0] = left[1] * right[2] - left[2] * right[1];
    res[1] = left[2] * right[0] - left[0] * right[2];
    res[2] = left[0] * right[1] - left[1] * right[0];
}

// POST: result contains the matrix-vector product of left and right
void matrix_vector_product(int (&res)[3], const int (&left)[3][3], const int (&right)[3])
{
    // row of left array
    for (int row = 0; row != 3; ++row) {
        int sum = 0;
        // column of right array
        for (int col = 0; col != 3; ++col) {
            // column of left array = row of right array
            sum += left[row][col] * right[col];
        }
        res[row] = sum;
    }
}

// POST: result contains the matrix product of left and right
void matrix_product(int (&res)[3][3], const int (&left)[3][3], const int (&right)[3][3])
{
    // row of left array
    for (int row = 0; row != 3; ++row) {
        // column of right array
        for (int col = 0; col != 3; ++col) {
            // column of left array = row of right array
            int sum = 0;
            for (int i = 0; i != 3; ++i){
                sum += left[row][i] * right[i][col];
            }
            res[row][col] = sum;
        }
    }
}

void vector_vector() {
    int vector1[3];
    int vector2[3];
    int res[3];
    
    input_vector(vector1);
    input_vector(vector2);
    
    cross_product(res, vector1, vector2);
    
    output_vector(res);
}

void matrix_vector() {
    int matrix[3][3];
    int vector[3];
    int res[3];
    
    input_matrix(matrix);
    input_vector(vector);
    
    matrix_vector_product(res, matrix, vector);
    
    output_vector(res);
}

void matrix_matrix() {
    int matrix1[3][3];
    int matrix2[3][3];
    int res[3][3];
    
    input_matrix(matrix1);
    input_matrix(matrix2);
    
    matrix_product(res, matrix1, matrix2);
    
    output_matrix(res);
}

int main() {
    char ltype;
    std::cout << "enter left operand type:\n";
    std::cin >> ltype;
    
    char rtype;
    std::cout << "enter right operand type:\n";
    std::cin >> rtype;
    
    if (ltype == 'v' && rtype == 'v') {
        vector_vector();
    } else if (ltype == 'm' && rtype == 'v') {
        matrix_vector();
    } else if (ltype == 'm' && rtype == 'm') {
        matrix_matrix();
    } else {
        std::cout << "unsupported operation\n";
    }
    
    return 0;
}
