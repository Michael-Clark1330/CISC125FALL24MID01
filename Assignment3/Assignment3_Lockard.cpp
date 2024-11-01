#include <iostream>
using namespace std;

template<typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

    void allocateMemory() {
        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        deallocateMemory();

        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    ~Matrix() {
        deallocateMemory();
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    void scalarMultiply(T scalar) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] *= scalar;
            }
        }
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    void input() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }
};

int main() {
    cout << "Fill Matrix 1 (integers):" << endl;
    cout << "Enter elements for a 2x2 matrix:" << endl;
    Matrix<int> mat1(2, 2);
    mat1.input();

    cout << "Fill Matrix 2 (integers):" << endl;
    cout << "Enter elements for a 2x2 matrix:" << endl;
    Matrix<int> mat2(2, 2);
    mat2.input();

    cout << "\nMatrix 1:" << endl;
    cout << mat1;

    cout << "Matrix 2:" << endl;
    cout << mat2;

    Matrix<int> sum = mat1 + mat2;
    cout << "\nMatrix Sum (Matrix 1 + Matrix 2):" << endl;
    cout << sum;

    Matrix<int> product = mat1 * mat2;
    cout << "Matrix Product (Matrix 1 * Matrix 2):" << endl;
    cout << product;

    mat1.scalarMultiply(2);
    cout << "Matrix 1 after scalar multiplication by 2:" << endl;
    cout << mat1;

    Matrix<int> transposed = mat1.transpose();
    cout << "Transpose of Matrix 1:" << endl;
    cout << transposed;

    return 0;
}
