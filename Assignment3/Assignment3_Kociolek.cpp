#include <iostream>
#include <stdexcept> 

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;  // Pointer to a 2D array 

public:
    // Constructor 
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];  
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];  
        }
    }

    // Destructor 
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];  
        }
        delete[] data; 
    }

    //  Constructor 
    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j]; 
            }
        }
    }

    // Assignment Operator, Deep copy for matrix assignment
    Matrix<T>& operator=(const Matrix<T>& other) {
        if (this == &other) {  // Self-assignment check
            return *this;
        }

        // Deallocate existing memory
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Copy new dimensions using the overloaded operators
        rows = other.rows;
        cols = other.cols;

        // Allocate new memory and copy data
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;  
    }

    
    T& at(int row, int col) {
        if (row >= rows || col >= cols || row < 0 || col < 0) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data[row][col];
    }

    
    const T& at(int row, int col) const {
        if (row >= rows || col >= cols || row < 0 || col < 0) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data[row][col];
    }

    
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // matrix addition
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

    // Overload
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

    // matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Incompatible matrix dimensions for multiplication.");
        }
        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.at(i, j) = 0;
                for (int k = 0; k < cols; ++k) {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

// Template function for scalar multiplication
template <typename T>
Matrix<T> scalarMultiply(const Matrix<T>& mat, T scalar) {
    Matrix<T> result(mat.getRows(), mat.getCols());
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            result.at(i, j) = mat.at(i, j) * scalar;
        }
    }
    return result;
}

// Template function to transpose the matrix
template <typename T>
Matrix<T> transpose(const Matrix<T>& mat) {
    Matrix<T> result(mat.getCols(), mat.getRows());  // Swap rows and columns
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            result.at(j, i) = mat.at(i, j);
        }
    }
    return result;
}

// Function to fill the matrix with user input
template <typename T>
void fillMatrix(Matrix<T>& mat) {
    std::cout << "Enter elements for a " << mat.getRows() << "x" << mat.getCols() << " matrix:\n";
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            std::cin >> mat.at(i, j);
        }
    }
}

// Main function 
int main() {
    // Create two 2x2 matrixes
    Matrix<int> mat1(2, 2);
    Matrix<int> mat2(2, 2);
    std::cout << "Fill Matrix 1 (integers):\n";
    fillMatrix(mat1);
    std::cout << "\nFill Matrix 2 (integers):\n";
    fillMatrix(mat2);

    // Display matrixes inputted by user
    std::cout << "\nMatrix 1:\n" << mat1;
    std::cout << "\nMatrix 2:\n" << mat2;

    // addition, multiplication, scalar multiplication
    Matrix<int> sum = mat1 + mat2;
    Matrix<int> product = mat1 * mat2;
    Matrix<int> scaled = scalarMultiply(mat1, 2);

  
    //failed to keep adjusted matrix 1 function. Takes prior mat1, not   scal multiplied
    Matrix<int> transposed = transpose(mat1);

  
    // Display results for adding
    std::cout << "\nMatrix Sum (Matrix 1 + Matrix 2):\n" << sum;
    
    // Display results for multiplication
    std::cout << "\nMatrix Product (Matrix 1 * Matrix 2):\n" << product;
    
    // Display results for scalar multiplication
    std::cout << "\nMatrix 1 after scalar multiplication by 2:\n" << scaled;
    
    // Display results for transpose
    std::cout << "\nTranspose of Matrix 1:\n" << transposed;
}