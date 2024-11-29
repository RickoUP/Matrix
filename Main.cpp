#include "Matrix.h"


Matrix<double> readFile(std::ifstream& inputFile) {
    
    int size;
    inputFile >> size;
    inputFile.ignore();
    inputFile.ignore();

    Matrix<double> res_mat(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> res_mat[i][j];
        }
    }
    return res_mat;

}


int main(int argc, char* argv[]) {

    std::ifstream inputFile(argv[2]);
    std::ofstream outputFile(argv[3]);

    if (!inputFile.is_open())
    {
        std::cout << "1243546";
        return 0;
    }
    Matrix<double> Mat(4);
    Mat = readFile(inputFile);
    Mat.out();
  
    std::cout << "============\n";
    //std::cout << "det = " << Mat.det() << '\n';

    std::cout << "============\n";
    Matrix<double> inverse(Mat.getSize());

    std::cout << Mat.det();
    inverse = Mat.inv();
    inverse.out();
    std::cout << "============\n";

    ///Mat.out();


}