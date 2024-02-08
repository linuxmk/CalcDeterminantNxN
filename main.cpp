#include "matrix.h"

using namespace std;

// Driver Code
int main()
{
    try
    {
        Matrix m("matrix.txt");
        float det = m.calcDeterNxN();
        cout << "Determinant: " << det << endl;

        Matrix m2 = m;
        det = m2.calcDeterNxN();
        cout << "Determinant: " << det << endl;

        Matrix m3 = std::move(m);
        det = m3.calcDeterNxN();
        cout << "Determinant: " << det << endl;
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << "\n";
    }



    return 0;
}
