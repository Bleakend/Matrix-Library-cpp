#pragma once

union numeric{
    int i;
    float f;
};

class Matrix {
private:
    int rows;
    int columns;
    bool is_squared;

    float** matrix_array;

public:
    Matrix(int num_rows, int num_columns);
    ~Matrix();

    void PrintMatrix();
    bool isSquaredMatrix();
    bool isZeroMatrix();
    bool isIdentityMatrix();
    bool isUpperTriangular();
    bool isLowerTriangular();

    void ClearMatrix();
    float GetDeterminant();
    void Transpose();

    //need to find a cleaner solution
    Matrix* set_row(int row, int row_content[]);
    Matrix* set_row(int row, float row_content[]);
    void  fill(float number);

    //operator overloading
    Matrix operator+(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
};
