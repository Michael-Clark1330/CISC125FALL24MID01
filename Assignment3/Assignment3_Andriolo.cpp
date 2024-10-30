#include <iostream>
#include <stdexcept>
using namespace std;


template <typename A>
class Matrix //created Matrix class
{
  private:
    int rows;
    int cols;
    A** array; //created array
    
  public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) //constructor
    {
      array = new A * [rows]; //allocating memory for the rows and columns
      
      for (int i = 0; i < rows; i++)
      {
        array[i] = new A[cols];
      }
    }
    
    
    ~Matrix() //destructor
    {
      
      for (int i = 0; i < rows; i++)
      {
        delete[] array[i];
      }
      
    delete[] array;
    
    }
    
    
    Matrix<A>(const Matrix<A>& prev) : rows(prev.rows), cols(prev.cols) //copy constructor to create deep copy
    {
      array = new A * [rows];
      
      for (int i = 0; i < rows; i++)
      {
        array[i] = new A[cols];
      
        for (int t = 0; t < cols; t++)
        {
          array[i][t] = prev.array[i][t];
        }
      }
    }
    
    
    Matrix<A>& operator=(const Matrix<A>& prev) //overload = to allow matrix assignment
    {
      if (this == &prev)
      {
        return *this;
      }
      
      for (int i = 0; i < rows; i++)
      {
        delete[] array[i];
      }
      delete array;
      
      rows = prev.rows;
      cols = prev.cols;
      
      array = new A * [rows];
      for (int i = 0; i < rows ; i++)
      {
        array[i] = new A[cols];
        
        for (int t = 0; t < cols; t++)
        {
          array[i][t] = prev.array[i][t];
        }
      }
      
      return *this;
      
    }
    
    
    A& at(int row, int col) //checking bounds
    {
      if (row < 0 || col < 0 || row >= rows || col >= cols) 
      {
        throw out_of_range("Index out of range");
      }
      
      return array[row][col];
      
    }
    
    
    const A& at(int row, int col) const //checking bounds
    {
      if (row < 0 || col < 0 || row >= rows || col >= cols) 
      {
        throw out_of_range("Index out of range");
      }
      
      return array[row][col];
      
    }
    
    //get rows and columns
    int getRows() const { return rows; }
    int getCols() const {return cols; }
    
    
    //overload operator +
    Matrix<A> operator+(const Matrix<A>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have equivalent dimensions.");
        }
        Matrix<A> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int t = 0; t < cols; ++t) {
                result.at(i, t) = this->at(i, t) + other.at(i, t);
            }
        }
        return result;
    }
    
    
    //overload operator -
    Matrix<A> operator-(const Matrix<A>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have equivalent dimensions.");
        }
        Matrix<A> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int t = 0; t < cols; ++t) {
                result.at(i, t) = this->at(i, t) - other.at(i, t);
            }
        }
        return result;
    }
    
    
    //overload operator *
     Matrix<A> operator*(const Matrix<A>& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Invalid dimensions.");
        }
        Matrix<A> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int t = 0; t < other.cols; ++t) {
                result.at(i, t) = 0;
                for (int p = 0; p < cols; ++p) {
                    result.at(i, t) += this->at(i, p) * other.at(p, t);
                }
            }
        }
        return result;
    }
    
    
    //overload << operator
    friend ostream& operator<<(ostream& os, const Matrix<A>& matx) {
        for (int i = 0; i < matx.rows; i++) {
            for (int t = 0; t < matx.cols; t++) {
                os << matx.array[i][t] << " ";
            }
            os << endl;
        }
        return os;
    }
};
    
    
  template <typename A> //scalar multiplication
  Matrix<A> scalarMultiply(const Matrix<A>& matx, A scalar) {
    Matrix<A> result(matx.getRows(), matx.getCols());
    for (int i = 0; i < matx.getRows(); i++) {
        for (int t = 0; t < matx.getCols(); ++t) {
            result.at(i, t) = matx.at(i, t) * scalar;
        }
    }
    return result;
}
    
    
template <typename A> //transpose matrix
Matrix<A> transpose(const Matrix<A>& matx) {
    Matrix<A> result(matx.getCols(), matx.getRows());  // Swap rows and columns
    for (int i = 0; i < matx.getRows(); ++i) {
        for (int t = 0; t < matx.getCols(); ++t) {
            result.at(t, i) = matx.at(i, t);
        }
    }
    return result;
}
    
    
  template <typename A> //fill matrix with input
  void fillMatrix(Matrix<A>& matx) {
    cout << "Enter elements for a " << matx.getRows() << "x" << matx.getCols() << " matrix: " << endl;
    for (int i = 0; i < matx.getRows(); ++i) {
        for (int t = 0; t < matx.getCols(); ++t) {
            cin >> matx.at(i, t);
        }
    }
}


int main() {
  
  Matrix<int> mat1(2, 2);
  Matrix<int> mat2(2, 2);
  
  cout << "Fill Matrix 1 (integers): " << endl;
  fillMatrix(mat1);
  cout << "Fill Matrix 2 (integers): " << endl;
  fillMatrix(mat2);

  //output each array
  cout << "Matrix 1: " << mat1 << endl;
  cout << "Matrix 2: " << mat2 << endl;

  //calculations
  Matrix<int> added = (mat1 + mat2);
  Matrix<int> multiplied = (mat1 * mat2);
  Matrix<int> scaled = scalarMultiply(mat1, 2);
  Matrix<int> transposed = transpose(mat1);
  
  
  //results
  cout << "Matrix Sum (Matrix 1 + Matrix 2): " << added << endl;
  
  cout << "Matrix Product (Matrix 1 * Matrix 2): " << multiplied << endl;
  
  cout << "Matrix 1 after scalar multiplication by 2: " << scaled << endl;
  
  
  
  
  
}