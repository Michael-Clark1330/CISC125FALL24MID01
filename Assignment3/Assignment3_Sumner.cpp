#include <iostream>
using namespace std;

template <typename T> class Matrix {
private:
    T** array;
    int rows;
    int cols;

public:
    //Constructor
    Matrix(T irows, T icols) : rows(irows), cols(icols) {
        matrix = new t*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
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
        matrix = new T&[rows];
        for (int a = 0; a < rows; a++) {
            matrix[i] = new T[cols];
            for (int b = 0, b < cols, b++) {
                matrix[a][b] = old.matrix[a][b]
            }
        }
    }

    //Overloading '=' operator
    const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& right) {
        if (this != &right) {
            for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
            }
            delete[] matrix;
            
            rows = right.rows;
            cols = right.cols;

            matrix = new T*[rows];
            for (int a = 0; a < rows; a++) {
                matrix[i] = new T[cols];
                for (int b = 0; b < rows; b++) {
                    matrix[a][b] = right.matrix[a][b];
                }
            }
        }
        return *this;
    }

    //Overloading the '+' operator
    Matrix<T> operator+(const Matrix<T>& first, const Matrix<T>& second) {
        if (first.rows == second.rows || second.cols == second.cols) {
            Matrix<T> sum(first.rows, first.cols);
            for (int a = 0; a < first.rows, a++) {
                for (int b = 0; b < first.rows, b++){
                    sum[a][b] = first[a][b] + second [a][b];
                }
            }
            return sum;
        }
        else {
            cout << "Error: incompatable dimensions"
        }
    }

    //Overloading the '-' operator
    Matrix<T> operator-(const Matrix<T>& first, const Matrix<T>& second) {
        if (first.rows == second.rows || second.cols == second.cols) {
            Matrix<T> difference(first.rows, first.cols);
            for (int a = 0; a < first.rows, a++) {
                for (int b = 0; b < first.rows, b++){
                    difference[a][b] = first[a][b] - second [a][b];
                }
            }
            return difference;
        }
        else {
            cout << "Error: incompatable dimensions"
        }
    }

    //Overloading the '*' operator
    Matrix<T> operator*(const Matrix<T>& first, const Matrix<T>& second) {
    if (first.cols == second.rows) {
            Matrix<T> product(first.rows, second.cols);
            for (int a = 0; a < first.rows, a++) {
                for (int b = 0; b < second.cols, b++) {
                    product[a][b] = 0;
                    for (int c = 0; c < first.cols; c++) {
                        product[a][b] += first[a][c] * second[c][b];
                    }
                }
            }
            return product;
        }
        else {
            cout << "Error: incompatable dimensions"
        }
    }

    //Overloading the '<<' operator
    friend ostream& operator<<(ostream& print, Matrix<T>& obj) {
        for (int a = 0; a < obj.rows; a++) {
            for (int b = 0; b < obj.cols; b++) {
                print << obj.matrix[a][b] < "     ";
            }
            print << "\n"
        }
        return print;
    }

    //Scalar multiplication function
    Matrix<T> scalarMult(Matrix<T>& obj, T scalar) {
        Matrix<T> out(obj.rows, obj.cols);
        for (int a = 0; a < obj.rows; a++) {
            for (int b = 0; b < obj.cols; b++) {
                out[a][b] = obj[a][b] * scalar
            }
        }
        return out;
    }

    //Transpose function
    Matrix<T> transpose(Matrix<T>& obj) {
        Matrix<T> out(obj.rows, obj.cols);
        for (int a = 0; a < obj.rows; a++) {
            for (int b = 0; b < obj.cols; b++) {
                out[b][a] = obj[a][b]
            }
        }
        return out; 
    }

    //Matrix value input function
    void getInput(Matrix<T>& obj) {
        cout << "Enter elements for a " << obj.rows << "x" << obj.cols << " matrix:\n";
         for (int a = 0; a < obj.rows; a++) {
            for (int b = 0; b < obj.cols; b++) {
                cin >> obj[a][b]
            }
        }
    }
};

int main() {
    Matrix<int> m1(2, 2);
    Matrix<int> m2(2, 2);
    
    cout << "Fill Matrix 1 (integers):\n";
    getInput(m1);

    cout << "\nFill Matrix 2 (integers):\n";
    getInput(m2);

    cout << "Matrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;

    Matrix<int> matrixA = m1 + m2;
    Matrix<int> matrixM = m1 * m2;
    Matrix<int> MatrixS = scalarMult(m1, m2);
    Matrix<int> MatrixT = transpose(m1);



    return 0
}


