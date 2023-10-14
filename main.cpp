#include <iostream>

#include "Matrix.h"


int  main(){
    std::cout << "Hello world" << std::endl;
    
    Matrix *a = new Matrix(2, 2);
    a->set_row(0, new int[2]{4, 3})
        ->set_row(1, new int[2]{0, 1});


    a->PrintMatrix();
    Matrix b(2, 2);
    b.set_row(0, new float[2]{0, 0})
        ->set_row(1, new float[2]{0, 0});

    b.PrintMatrix();
    std::cout << b.GetDeterminant() << std::endl;
    
    Matrix c = (*a) + b;
    c.PrintMatrix();
    std::cout << std::endl << std::endl;
    Matrix d = (*a) * b;
    d.PrintMatrix();
    //delete a;
    std::cout << std::endl << std::endl;

    Matrix e(3, 3);
    Matrix f(3, 1);
    e.set_row(0, new int[3]{1, 2, 3})
        ->set_row(1, new int[3]{3, 4, 5})
        ->set_row(2, new int[3]{1, 2, 3});

    f.set_row(0, new int[1]{1})
        ->set_row(1, new int[1]{2})
        ->set_row(2, new int[1]{3});

    Matrix j = e * f;
    j.PrintMatrix();
    std::cout << "!!!!!!!!!!!!!" << std::endl;
    // std::cout << a->isUpperTriangular() << std::endl;
    // std::cout << a->isLowerTriangular() << std::endl;
    j.PrintMatrix();
    j.Transpose();
    std::cout << std::endl;
    j.PrintMatrix();


}
