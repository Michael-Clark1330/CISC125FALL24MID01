#include <iostream>
#include <stdexcept>  // For exceptions

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** elements;  // Pointer to a dynamically allocated 2D array

public:
    // Constructor to initialize a matrix with specified number of rows and columns
    Matrix(int r, int c) : rows(r), cols(c) {
        elements = new T*[rows];  // Allocate memory for row pointers
        for (int i = 0; i < rows; ++i) {
            elements[i] = new T[cols];  // Allocate memory for columns in each row
        }
    }

    // Destructor to release dynamically allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] elements[i];  // Free each row's memory
        }
        delete[] elements;  // Free the array of row pointers
    }

    // Copy Constructor: Performs a deep copy of another matrix
    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
        elements = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            elements[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                elements[i][j] = other.elements[i][j];  // Copy each element
            }
        }
    }

    // Assignment Operator: Deep copy assignment for matrix assignment
    Matrix<T>& operator=(const Matrix<T>& other) {
        if (this != &other) {  // Self-assignment check
            // Deallocate existing memory
            for (int i = 0; i < rows; ++i) {
                delete[] elements[i];
            }
            delete[] elements;

            // Copy new dimensions
            rows = other.rows;
            cols = other.cols;

            // Allocate new memory and copy data
            elements = new T*[rows];
            for (int i = 0; i < rows; ++i) {
                elements[i] = new T[cols];
                for (int j = 0; j < cols; ++j) {
                    elements[i][j] = other.elements[i][j];
                }
            }
        }
        return *this;  // Allow chained assignment
    }

    // Accessor mto get and set matrix elements with bounds checking
    T& at(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[row][col];
    }

    // Const version for read-only access to matrix elements
    const T& at(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[row][col];
    }

    // Getters for number of rows and columns
    int getRowCount() const { return rows; }
    int getColumnCount() const { return cols; }

    // Overloaded (+) operator for addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.at(i, j) = this->at(i, j) + other.at(i, j);
            }
        }
        return result;
    }

    // Overloaded (-) operator for subtraction
    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.at(i, j) = this->at(i, j) - other.at(i, j);
            }
        }
        return result;
    }

    // Overloaded (*) operator for multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Incompatible dimensions for matrix multiplication.");
        }
        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.at(i, j) = 0;  // Initialize the result element to 0
                for (int k = 0; k < cols; ++k) {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }
        return result;
    }

    // Overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                os << mat.elements[i][j] << " ";  // Print each element
            }
            os << std::endl;  // New line after each row
        }
        return os;
    }
};

// Func for scalar multiplication
template <typename T>
Matrix<T> scalarMultiply(const Matrix<T>& mat, T scalar) {
    Matrix<T> result(mat.getRowCount(), mat.getColumnCount());
    for (int i = 0; i < mat.getRowCount(); ++i) {
        for (int j = 0; j < mat.getColumnCount(); ++j) {
            result.at(i, j) = mat.at(i, j) * scalar;  // Multiply by scalar
        }
    }
    return result;
}

// Func to transpose the matrix
template <typename T>
Matrix<T> transpose(const Matrix<T>& mat) {
    Matrix<T> result(mat.getColumnCount(), mat.getRowCount());  // Swap dimensions
    for (int i = 0; i < mat.getRowCount(); ++i) {
        for (int j = 0; j < mat.getColumnCount(); ++j) {
            result.at(j, i) = mat.at(i, j);  // Transpose elements
        }
    }
    return result;
}

// Func to fill the matrix with user input
template <typename T>
void fillMatrix(Matrix<T>& mat) {
    std::cout << "Enter elements for a " << mat.getRowCount() << "x" << mat.getColumnCount() << " matrix:\n";
    for (int i = 0; i < mat.getRowCount(); ++i) {
        for (int j = 0; j < mat.getColumnCount(); ++j) {
            std::cin >> mat.at(i, j);  // Read element from user
        }
    }
}

// Main function to demonstrate the Matrix class
int main() {
    // Create two 2x2 matrices of integers and fill them with user input
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);
    
    std::cout << "Fill Matrix 1 (integers):\n";
    fillMatrix(matrix1);
    
    std::cout << "\nFill Matrix 2 (integers):\n";
    fillMatrix(matrix2);

    // Display both matrices
    std::cout << "\nMatrix 1:\n" << matrix1;
    std::cout << "Matrix 2:\n" << matrix2;

    // Perform addition, multiplication, and scalar multiplication
    Matrix<int> matrixSum = matrix1 + matrix2;
    Matrix<int> matrixProduct = matrix1 * matrix2;
    Matrix<int> scaledMatrix = scalarMultiply(matrix1, 2);
    Matrix<int> transposedMatrix = transpose(matrix1);

    // Display results
    std::cout << "\nMatrix Sum (Matrix 1 + Matrix 2):\n" << matrixSum;
    std::cout << "Matrix Product (Matrix 1 * Matrix 2):\n" << matrixProduct;
    std::cout << "Matrix 1 after scalar multiplication by 2:\n" << scaledMatrix;
    std::cout << "Transpose of Matrix 1:\n" << transposedMatrix;

    return 0;
}
