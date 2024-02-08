#include "matrix.h"

Matrix::Matrix(const std::string& fileName)
{
    if(readMatrix(fileName) == -1)
        throw std::runtime_error("Invalid matrix read");
}

// Function to calculate the determinant of a matrix
float Matrix::calcDeterNxN()
{
    return calcDeter(mMatrix,mSize);
}

float Matrix::calcDeter(vector<vector<float>>& matrix, size_t size)
{
    float det = 0;

    // Base Case
    if (size == 1)
    {
        det = matrix[0][0];
    }
    else
    if (size == 2)// Base case: If the matrix is 2x2, return the determinant using the formula
    {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        // Iterate over the elements of the first row and calculate the determinant
        for (int j = 0; j < size; ++j)
        {
            // Calculate the submatrix by removing the current row and column
            vector<vector<float>> subMatrix(size - 1, vector<float>(size - 1, 0));
            for (int i = 1; i < size; ++i)
            {
                for (int k = 0, col = 0; k < size; ++k)
                {
                    if (k != j)
                    {
                        subMatrix[i - 1][col++] = matrix[i][k];
                    }
                }
            }

            // Use the Laplace expansion formula recursively
            det += matrix[0][j] * (j % 2 == 0 ? 1 : -1) * calcDeter(subMatrix, subMatrix.size());
        }
    }

    return det;
}

int Matrix::readMatrix(const std::string& fileName)
{
    std::ifstream file(fileName);
    if(!file.is_open())
    {
        std::cerr << "Can not open file "<< fileName << "\n";
        return -1;
    }

    file >> mSize ;
    if(!mSize)
    {
        std::cerr << "Empty matrix file\n";
        return -1;
    }

    for(size_t i = 0 ; i < mSize ; ++i)
    {
        std::vector<float> temp_vec(mSize);

        for(size_t j = 0 ; j < mSize ; ++j)
        {
            file >> temp_vec[j];
        }

        mMatrix.push_back(temp_vec);
    }

    return 0;
}
