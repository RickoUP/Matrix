
#include <iostream>
#include <fstream>
#include "Matrix.h"

Matrix<int> readFile(std::ifstream& inputFile) {
    int size;
    inputFile >> size;
    inputFile.ignore();
    inputFile.ignore();

    Matrix<int> res_mat(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> res_mat[i][j];
        }
    }
    return res_mat;

}


int main(int argc, char* argv[]) {

    std::ifstream inputFile(argv[2]);
    std::fstream outputFile(argv[3]);

    if (!inputFile.is_open())
    {
        std::cout << "1243546";
        return 0;
    }
    Matrix<int> Mat(4);
    Mat = readFile(inputFile);
    Mat.out();
    

    std::cout << Mat.det();


}