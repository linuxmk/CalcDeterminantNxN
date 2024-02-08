#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
using namespace std;

class Matrix
{
public:
    Matrix(const string &fileName);
    int readMatrix(const std::string& fileName);
    float calcDeterNxN();
private:
    float calcDeter(vector<vector<float>>& mat, size_t size);

    std::vector<std::vector<float>>         mMatrix;
    size_t                                  mSize;

};

#endif // MATRIX_H
