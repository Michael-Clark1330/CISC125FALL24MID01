#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

    void allocateMemory() {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory();
    }

    // Destructor
    ~Matrix() {
        deallocateMemory();
    }

    // Copy Constructor
    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }

    // Assignment Operator
    Matrix<T>& operator=(const Matrix<T>& other) {
        if (this != &other) {
            deallocateMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] = other.data[i][j];
        }
        return *this;
    }

    // Overload + Operator
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions do not match for addition");
        
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        
        return result;
    }

    // Overload - Operator
    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions do not match for subtraction");
        
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        
        return result;
    }

    // Overload * Operator for Matrix Multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw invalid_argument("Matrix dimensions do not match for multiplication");

        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        return result;
    }

    // Overload << Operator
    friend ostream& operator<<(ostream& os, const Matrix<T>& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j)
                os << matrix.data[i][j] << " ";
            os << endl;
        }
        return os;
    }

    // Method to set matrix element
    void setElement(int r, int c, T value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Invalid index");
        data[r][c] = value;
    }

    // Method to fill the matrix from user input
    void fillMatrix() {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }

    // Friend function for scalar multiplication
    template <typename U>
    friend Matrix<U> scalarMultiply(const Matrix<U>& matrix, U scalar);

    // Friend function for transpose
    template <typename U>
    friend Matrix<U> transpose(const Matrix<U>& matrix);
};

// Scalar Multiplication Template Function
template <typename T>
Matrix<T> scalarMultiply(const Matrix<T>& matrix, T scalar) {
    Matrix<T> result(matrix.rows, matrix.cols);
    for (int i = 0; i < matrix.rows; ++i)
        for (int j = 0; j < matrix.cols; ++j)
            result.data[i][j] = matrix.data[i][j] * scalar;
    return result;
}

// Transpose Template Function
template <typename T>
Matrix<T> transpose(const Matrix<T>& matrix) {
    Matrix<T> result(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; ++i)
        for (int j = 0; j < matrix.cols; ++j)
            result.data[j][i] = matrix.data[i][j];
    return result;
}

// Main Function for Testing
int main() {
    // Fill and display integer matrices
    cout << "Fill Matrix 1 (integers):\n";
    Matrix<int> mat1(2, 2);
    mat1.fillMatrix();

    cout << "Fill Matrix 2 (integers):\n";
    Matrix<int> mat2(2, 2);
    mat2.fillMatrix();

    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;

    // Perform and display matrix addition
    Matrix<int> resultAdd = mat1 + mat2;
    cout << "Matrix Sum (Matrix 1 + Matrix 2):\n" << resultAdd;

    // Perform and display matrix multiplication
    Matrix<int> resultMul = mat1 * mat2;
    cout << "Matrix Product (Matrix 1 * Matrix 2):\n" << resultMul;

    // Perform and display scalar multiplication
    Matrix<int> resultScalar = scalarMultiply(mat1, 2);
    cout << "Matrix 1 after Scalar Multiplication by 2:\n" << resultScalar;

    // Perform and display transpose of Matrix 1
    Matrix<int> resultTranspose = transpose(mat1);
    cout << "Transpose of Matrix 1:\n" << resultTranspose;

    return 0;
}