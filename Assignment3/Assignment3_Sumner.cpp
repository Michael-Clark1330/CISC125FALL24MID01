#include <iostream>
using namespace std;

template <typename T> class Matrix {
private:
    T** matrix;
    int rows;
    int cols;

public:
    //Constructor
    Matrix(int irows, int icols) : rows(irows), cols(icols) {
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }
    }

    T& operator[] (int index);

    //Matrix value input function
    void getInput() {
        cout << "Enter elements for a " << this->rows << "x" << this->cols << " matrix:\n";
         for (int a = 0; a < this->rows; a++) {
            for (int b = 0; b < this->cols; b++) {
                cin >> this[a][b];
            }
        }
    }

    //Destrictor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    //Copy Constructor
    Matrix<T>(const Matrix<T> &old) : rows(old.rows), cols(old.cols) {
        matrix = new T*[rows];
        for (int a = 0; a < rows; a++) {
            matrix[a] = new T[cols];
            for (int b = 0; b < cols; b++) {
                matrix[a][b] = old.matrix[a][b];
            }
        }
    }

    //Overloading '=' operator
    Matrix<T>& operator=(const Matrix<T>& right) {
        if (this != &right) {
            for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
            }
            delete[] matrix;
            
            rows = right.rows;
            cols = right.cols;

            matrix = new T*[rows];
            for (int a = 0; a < rows; a++) {
                matrix[a] = new T[cols];
                for (int b = 0; b < rows; b++) {
                    matrix[a][b] = right.matrix[a][b];
                }
            }
        }
        return *this;
    }

    //Overloading the '+' operator
    Matrix<T> operator+(const Matrix<T>& second) {
        if (this->rows == second.rows || this->cols == second.cols) {
            Matrix<T> sum(this->rows, this->cols);
            for (int a = 0; a < this->rows; a++) {
                for (int b = 0; b < this->rows; b++) {
                    sum[a][b] = this[a][b] + second[a][b];
                }
            }
            return sum;
        }
        else {
            cout << "Error: incompatable dimensions";
        }
    }

    //Overloading the '-' operator
    Matrix<T> operator-(const Matrix<T>& second) {
        if (this->rows == second.rows || this->cols == second.cols) {
            Matrix<T> difference(this->rows, this->cols);
            for (int a = 0; a < this->rows; a++) {
                for (int b = 0; b < this->rows; b++){
                    difference[a][b] = this[a][b] - second[a][b];
                }
            }
            return difference;
        }
        else {
            cout << "Error: incompatable dimensions";
        }
    }

    //Overloading the '*' operator
    Matrix<T> operator*(const Matrix<T>& second) {
    if (this->cols == second.rows) {
            Matrix<T> product(this->rows, second.cols);
            for (int a = 0; a < this->rows; a++) {
                for (int b = 0; b < second.cols; b++) {
                    product[a][b] = 0;
                    for (int c = 0; c < this->cols; c++) {
                        product[a][b] += this[a][c] * second[c][b];
                    }
                }
            }
            return product;
        }
        else {
            cout << "Error: incompatable dimensions";
        }
    }

    //Overloading the '<<' operator
    friend ostream& operator<<(ostream& print, Matrix<T>& obj) {
        for (int a = 0; a < obj.rows; a++) {
            for (int b = 0; b < obj.cols; b++) {
                print << obj.matrix[a][b] << "     ";
            }
            print << "\n";
        }
        return print;
    }

    //Scalar multiplication function
    Matrix<T> scalarMult(T scalar) {
        Matrix<T> out(this->rows, this->cols);
        for (int a = 0; a < this->rows; a++) {
            for (int b = 0; b < this->cols; b++) {
                out[a][b] = this[a][b] * scalar;
            }
        }
        return out;
    }

    //Transpose function
    Matrix<T> transpose() {
        Matrix<T> out(this->rows, this->cols);
        for (int a = 0; a < this->rows; a++) {
            for (int b = 0; b < this->cols; b++) {
                out[b][a] = this[a][b];
            }
        }
        return out; 
    }

};

int main() {
    Matrix<int> m1(2, 2);
    Matrix<int> m2(2, 2);
    
    cout << "Fill Matrix 1 (integers):\n";
    m1.getInput();

    cout << "\nFill Matrix 2 (integers):\n";
    m2.getInput();

    cout << "Matrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;

    Matrix<int> matrixA = m1 + m2;
    Matrix<int> matrixM = m1 * m2;
    Matrix<int> matrixS = m1.scalarMult(2);
    Matrix<int> matrixT = m1.transpose();

    return 0;
}
