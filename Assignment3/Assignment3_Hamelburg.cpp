#include <iostream>
using namespace std;

template<typename M>
class Matrix { 
public:
    M** matrixData;
    int rows, cols;

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrixData = new M * [rows];
        for (int i = 0; i < rows; i++) {
            matrixData[i] = new M[cols];
            for (int j = 0; j < cols; j++) {
                matrixData[i][j] = 0;
            }
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrixData[i];
        }

        delete[] matrixData;
    }

    //COPY
    Matrix(const Matrix& otherMatrix) : rows(otherMatrix.rows), cols(otherMatrix.cols) {
        matrixData = new M * [rows];

        for (int i = 0; i < rows; i++) {
            matrixData[i] = new M[cols];

            for (int j = 0; j < cols; j++) {
                matrixData[i][j] = otherMatrix.matrixData[i][j];
            }
        }
    }

    void fillMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                M enter;
                cin >> enter;
                matrixData[i][j] = enter;
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other)const {
        Matrix<M> RETURN_MATRIX(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                RETURN_MATRIX.matrixData[i][j] = this->matrixData[i][j] + other.matrixData[i][j];
            }
        }

        return RETURN_MATRIX;
    }

    Matrix operator-(const Matrix& other)const {
        Matrix<M> RETURN_MATRIX(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                RETURN_MATRIX.matrixData[i][j] = this->matrixData[i][j] - other.matrixData[i][j];
            }
        }

        return RETURN_MATRIX;
    }

    Matrix operator*(const Matrix& other)const {
        Matrix<M> RETURN_MATRIX(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                RETURN_MATRIX.matrixData[i][j] = this->matrixData[i][j] * other.matrixData[i][j];
            }
        }

        return RETURN_MATRIX;
    }

    friend ostream& operator<<(ostream& os, const Matrix& other) {
        for (int i = 0; i < other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                os << other.matrixData[i][j] << " ";
            }
            cout << endl;
        }

        return os;
    }

    Matrix operator= (const Matrix& other) noexcept{
        if (this != &other) {

        }

        rows = other.rows;
        cols = other.cols;
       

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrixData[i][j] = other.matrixData[i][j];
            }
        }

        return *this;
    }
};

template<typename T>
void scalarMultiply(const Matrix<T>& matrix, T scalar) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            matrix.matrixData[i][j] = matrix.matrixData[i][j] * scalar;
        }
    }

    cout << "Matrix 1 after scalar multiplication by " << scalar << ": " << endl;
    cout << matrix << endl;
}


void matrixINT(int rows, int cols);
void matrixFloat(int rows, int cols);
void matrixDouble(int rows, int cols);
int main()
{
    int rows, cols;
    int typeNameChoice;
    cout << "Hello! Pick the Number of Rows and Columns for Both Matrixes" << endl;
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> cols;

   

    cout << "Pick the Matrix Type - 1 for Integers | 2 for Floats | 3 for Doubles: ";
    cin >> typeNameChoice;
    if (typeNameChoice == 1) {
        matrixINT(rows, cols);
    }
    else if (typeNameChoice == 2) {
        matrixFloat(rows, cols);
    }
    else if (typeNameChoice == 3) {
        matrixDouble(rows, cols);
    }
    else {
        cout << "Invaild choice" << endl;
    }

}
void matrixINT(int rows, int cols) {
    Matrix<int> MATRIX_ONE(rows, cols);
    Matrix<int> MATRIX_TWO(rows, cols);

    Matrix<int> RESULT(rows, cols);

    cout << "Fill Matrix 1 " << "(integers):" << endl;
    cout << "Enter Elements for a " << rows << "x" << cols << "matrix: " << endl;

    MATRIX_ONE.fillMatrix();

    cout << "Fill Matrix 2 " << "(integers):" << endl;
    cout << "Enter Elements for a " << rows << "x" << cols << "matrix: " << endl;

    MATRIX_TWO.fillMatrix();

    cout << "Matrix 1:" << endl;
    cout << MATRIX_ONE << endl;
    cout << "Matrix 2: " << endl;
    cout << MATRIX_TWO << endl;

    //ADDING
    cout << "Matrix Sum (Matrix 1 + Matrix 2) " << endl;
        RESULT = MATRIX_ONE + MATRIX_TWO;
    cout << RESULT << endl;

    //MULTIPY
    cout << "Matrix Product (Matrix 1 * Matrix 2) " << endl;
    RESULT = MATRIX_ONE * MATRIX_TWO;
    cout << RESULT << endl;

    scalarMultiply(MATRIX_ONE, 2);
}


void matrixFloat(int rows, int cols) {
    Matrix<float> MATRIX_ONE(rows, cols);
    Matrix<float> MATRIX_TWO(rows, cols);

    Matrix<float> RESULT(rows, cols);

    cout << "Fill Matrix 1 " << "(floats):" << endl;
    cout << "Enter Elements for a " << rows << "x" << cols << "matrix: " << endl;

    MATRIX_ONE.fillMatrix();

    cout << "Fill Matrix 2 " << "(floats):" << endl;
    cout << "Enter Elements for a " << rows << "x" << cols << "matrix: " << endl;

    MATRIX_TWO.fillMatrix();

    cout << "Matrix 1:" << endl;
    cout << MATRIX_ONE << endl;
    cout << "Matrix 2: " << endl;
    cout << MATRIX_TWO << endl;

    //ADDING
    cout << "Matrix Sum (Matrix 1 + Matrix 2) " << endl;
    RESULT = MATRIX_ONE + MATRIX_TWO;
    cout << RESULT << endl;

    //MULTIPY
    cout << "Matrix Product (Matrix 1 * Matrix 2) " << endl;
    RESULT = MATRIX_ONE * MATRIX_TWO;
    cout << RESULT << endl;

}


void matrixDouble(int rows, int cols) {
    Matrix<double> MATRIX_ONE(rows, cols);
    Matrix<double> MATRIX_TWO(rows, cols);

    Matrix<double> RESULT(rows, cols);

    cout << "Fill Matrix 1 " << "(doubles):" << endl;
    cout << "Enter Elements for a " << rows << "x" << cols << "matrix: " << endl;

    MATRIX_ONE.fillMatrix();

    cout << "Fill Matrix 2 " << "(doubles):" << endl;
    cout << "Enter Elements for a " << rows << "x" << cols << "matrix: " << endl;

    MATRIX_TWO.fillMatrix();

    cout << "Matrix 1:" << endl;
    cout << MATRIX_ONE << endl;
    cout << "Matrix 2: " << endl;
    cout << MATRIX_TWO << endl;

    //ADDING
    cout << "Matrix Sum (Matrix 1 + Matrix 2) " << endl;
    RESULT = MATRIX_ONE + MATRIX_TWO;
    cout << RESULT << endl;

    //MULTIPY
    cout << "Matrix Product (Matrix 1 * Matrix 2) " << endl;
    RESULT = MATRIX_ONE * MATRIX_TWO;
    cout << RESULT << endl;


}
