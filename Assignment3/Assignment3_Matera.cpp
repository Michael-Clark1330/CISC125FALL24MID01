#include <iostream>
#include <stdexcept>
#include <iomanip>

template <typename T>
class Matrix {
private:
    T** data;   // Pointer to hold the matrix data
    size_t rows, cols;

public:
    // Constructor
    Matrix(size_t rows, size_t cols, T init_val = T()) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = init_val;
            }
        }
    }

    // Destructor to free allocated memory
    ~Matrix() {
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Copy Constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new T*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Assignment Operator
    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this; // Handle self-assignment

        // Deallocating current memory
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Allocating new memory and copying data
        rows = other.rows;
        cols = other.cols;
        data = new T*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    // Overloading the stream insertion operator <<
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                out << std::setw(5) << matrix.data[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }

    // Overloading the addition operator +
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrices dimensions must match for addition.");

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        
        return result;
    }

    // Overloading the subtraction operator -
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrices dimensions must match for subtraction.");

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        
        return result;
    }

    // Overloading the multiplication operator *
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw std::invalid_argument("Matrices dimensions are not compatible for multiplication.");

        Matrix result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        
        return result;
    }

    // The Access element
    T& operator()(size_t row, size_t col) {
        if (row >= rows || col >= cols)
            throw std::out_of_range("Matrix index out of range.");
        return data[row][col];
    }

    const T& operator()(size_t row, size_t col) const {
        if (row >= rows || col >= cols)
            throw std::out_of_range("Matrix index out of range.");
        return data[row][col];
    }
};

int main() {
    // The Example usage
    Matrix<int> mat1(2, 2);
    mat1(0, 0) = 1; mat1(0, 1) = 2;
    mat1(1, 0) = 3; mat1(1, 1) = 4;

    Matrix<int> mat2(2, 2);
    mat2(0, 0) = 5; mat2(0, 1) = 6;
    mat2(1, 0) = 7; mat2(1, 1) = 8;

    // Displaying matrices
    std::cout << "Matrix 1:\n" << mat1 << "\n";
    std::cout << "Matrix 2:\n" << mat2 << "\n";

    // Adding matrices
    Matrix<int> mat3 = mat1 + mat2;
    std::cout << "Matrix 1 + Matrix 2:\n" << mat3 << "\n";

    // Subtracting matrices
    Matrix<int> mat4 = mat1 - mat2;
    std::cout << "Matrix 1 - Matrix 2:\n" << mat4 << "\n";

    // Multiplying matrices
    Matrix<int> mat5 = mat1 * mat2;
    std::cout << "Matrix 1 * Matrix 2:\n" << mat5 << "\n";

    return 0;
}
