#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int num_rows, int num_columns)
    : rows(num_rows), columns(num_columns) {
    is_squared = (num_columns == num_rows); 
    matrix_array = new float*[num_rows];

    for (size_t i = 0; i < num_rows; ++i) {
        matrix_array[i] = new float[num_columns];

        for (size_t j = 0; j < num_columns; j++) {
            matrix_array[i][j] = 0.0f;
        }
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix_array[i]; // Delete each inner array
    }
    delete[] matrix_array; // Delete the array of pointers
}

void Matrix::PrintMatrix() {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            std::cout << matrix_array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Matrix::isSquaredMatrix() {
    return is_squared;
}

bool Matrix::isZeroMatrix() {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (matrix_array[i][j] != 0.0f) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isIdentityMatrix() {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (i == j && matrix_array[i][j] != 1.0f) {
                return false;
            }
            if (i != j && matrix_array[i][j] != 0.0f) {
                return false;
            }
        }
    }
    return true;
}

//not right
bool Matrix::isUpperTriangular(){
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            if(i > j && matrix_array[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isLowerTriangular(){
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            if(j > i && matrix_array[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

void Matrix::ClearMatrix() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; j++) {
            matrix_array[i][j] = 0.0f;
        }
    }
}

float Matrix::GetDeterminant() {
    float result = 0.0f;
    if (!is_squared) {
        return -1.0f;
    }
    if (rows == 2) {
        return (matrix_array[1][1] * matrix_array[0][0]) - (matrix_array[1][0] * matrix_array[0][1]);
    }

    for (size_t i = 0; i < rows; i++) {
        Matrix* temp = new Matrix(rows - 1, columns - 1);
        for (size_t j = 1; j < rows; j++) {
            int col = 0;
            for (size_t k = 0; k < columns; k++) {
                if (k != i) {
                    temp->matrix_array[j - 1][col++] = matrix_array[j][k];
                }
            }
        }
        float sign = (i % 2 == 0) ? 1.0f : -1.0f;
        result += sign * matrix_array[0][i] * temp->GetDeterminant();
        delete temp;
    }
    return result;
}

void Matrix::Transpose(){
    float** temp = new float*[columns];
    int temp_rows = rows;
    rows = columns;
    columns = temp_rows;
    for(size_t i = 0; i < rows; i++){
        temp[i] = new float[columns];

        for(size_t j = 0; j < columns; j++){
            temp[i][j] = matrix_array[j][i];
        }
    }
    delete[] matrix_array;
    matrix_array = temp;

}


Matrix* Matrix::set_row(int row, int row_content[]) {
    for (size_t i = 0; i < columns; i++) {
        matrix_array[row][i] = row_content[i];
    }
    return this;
}

Matrix* Matrix::set_row(int row, float row_content[]) {
    for (size_t i = 0; i < columns; i++) {
        matrix_array[row][i] = row_content[i];
    }
    return this;
}

void Matrix::fill(float number){
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            matrix_array[i][j] = number;
        }
    }
}

Matrix Matrix::operator+(const Matrix &other) const {
    // Check if matrices have compatible dimensions for addition
    if (rows != other.rows || columns != other.columns) {
        throw std::invalid_argument("Matrix dimensions are not compatible for addition");
    }

    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result.matrix_array[i][j] = matrix_array[i][j] + other.matrix_array[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix &other) const{
    if (columns != other.rows) {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplications");
    }

    Matrix result(rows, other.columns);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < other.columns; j++){
            float result_multiplication{0};
            for(size_t k = 0; k < columns; k++){
                result_multiplication += matrix_array[i][k] * other.matrix_array[k][j];
            }
            result.matrix_array[i][j] = result_multiplication;
        }
    }
    return result;
}


