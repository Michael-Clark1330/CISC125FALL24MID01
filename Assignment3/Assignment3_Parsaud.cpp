#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Matrix class is added first.
template <typename T>
class Matrix {
    int rows, cols;
    T** data;

    void allocateMemory() {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]();
    }

public:
    Matrix(int r, int c) : rows(r), cols(c) { allocateMemory(); }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) { 
        allocateMemory();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) delete[] data[i];
        delete[] data;
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (int i = 0; i < rows; ++i) delete[] data[i];
            delete[] data;
            rows = other.rows; cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] = other.data[i][j];
        }
        return *this;
    }

    // Additional operator to add another Matrix.
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    // Values are then set for this method to allow multiplication.
    void setValues() {
        cout << "Enter values for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
    }

    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j)
                os << setw(5) << matrix.data[i][j] << " ";
            os << endl;
        }
        return os;
    }

    friend void scalarMultiply(Matrix& matrix, T scalar) {
        for (int i = 0; i < matrix.rows; ++i)
            for (int j = 0; j < matrix.cols; ++j)
                matrix.data[i][j] *= scalar;
    }

    friend Matrix transpose(const Matrix& matrix) {
        Matrix result(matrix.cols, matrix.rows);
        for (int i = 0; i < matrix.rows; ++i)
            for (int j = 0; j < matrix.cols; ++j)
                result.data[j][i] = matrix.data[i][j];
        return result;
    }
};

int main() {
    Matrix<int> mat1(2, 2);
    mat1.setValues();  // We uset his to fill in the inputs.

    cout << "Matrix after setting values:\n" << mat1 << endl;

    Matrix<int> mat2(2, 2);
    mat2.setValues();

    Matrix<int> result = mat1 + mat2;
    cout << "Result of matrix addition:\n" << result << endl;

    return 0;
}
