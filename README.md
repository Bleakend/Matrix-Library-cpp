# Matrix Library

## Description

This is a personal side project that involves building a Matrix class, allowing users to create Matrix objects and perform simple operations on those matrices.

## Project Structure

The project includes the following files:

1. `Matrix.h`: This header file contains the declaration of the Matrix class, which includes the class definition and its member functions.

2. `Matrix.cpp`: The source file contains the implementation of the Matrix class, including the details of how the class functions are defined.

3. `Main.cpp`: This file serves as a usage example of the Matrix library. It demonstrates how to create Matrix objects and perform basic operations on them.

## Usage

To use the Matrix Library, follow these steps:

1. Include the `Matrix.h` header file in your project.

2. Create instances of the Matrix class to work with matrices.

3. Utilize the provided methods to perform operations on the matrices.

Here's a simple example of how to use the Matrix Library in your code:

```cpp
#include "Matrix.h"

int main() {
    // Create matrices
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);

    // Populate matrices
    matrix1.fill(1);
    matrix2.fill(2);

    // Perform matrix addition
    Matrix result(2, 2) = matrix1 + matrix2;

    // Display the result
    result.PrintMatrix();

    return 0;
}
