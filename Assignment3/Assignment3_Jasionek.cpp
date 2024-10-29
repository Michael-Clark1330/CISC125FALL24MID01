// CSproject3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <stdexcept> // Added for exception handling

template <typename T>
class Matrix
{
private:
	int rows;
	int cols;
	T** elements;
public:
	Matrix(int m_rows, int m_cols) : rows(m_rows), cols(m_cols), elements(nullptr) { // Modified to initialize elements properly
		if (rows > 0 && cols > 0) {
			elements = new T * [rows];
			for (int i = 0; i < rows; ++i) {
				elements[i] = new T[cols]{}; // Initialize elements to zero
			}
		}
	}
	~Matrix() { deallocateMemory();	}

	// A method to assign elements to their respective i-th j-th position
	void assignElements() { 
		// if (elements != nullptr) {
		// 	deallocateMemory();
		// }

		// Assign matrix elements
		if (rows > 0 && cols > 0) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					std::cout << "Enter element [" << i << "][" << j << "]: "; 
					std::cin >> elements[i][j];
				}
			}
		}
	}

	// A method to deallocate elements
	void deallocateMemory() {
		if (elements) {
			for (int i = 0; i < rows; i++) {
				delete[] elements[i];
			}
			delete[] elements;
			elements = nullptr;
		}
		// rows = 0;
		// cols = 0;
	}

	// A method for scaling a matrix by a scalar
	Matrix<T> scalarMultiply(T scalar) const {
		Matrix resulting_matrix(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				resulting_matrix.elements[i][j] = this->elements[i][j] * scalar;
			}
		}
		return resulting_matrix;
	}

	// A method for transposing a matrix
	Matrix<T> transpose() const {
		// [[1,2],[3,4]]^T --> [[1,3],[2,4]]
		// A transpose can be seen as "inverting" indices
		//		So flip indices, keeping in mind the bounds of the iteration
		Matrix<T> resulting_matrix(cols, rows);
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				resulting_matrix.elements[i][j] = this->elements[j][i];
			}
		}
		return resulting_matrix;
	}

	// Accessor for rows
	int getRows() const { return rows; }

	// Accessor for columns
	int getCols() const { return cols; }

	// Get element value
	T getElement(int r, int c) const { return elements[r][c]; }

	// Operator Overloadings
	// Need to overload operator<< to display matrices
	template <typename M>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<M>& matrix);

	// Need to overload operator+ for elementwise (matrix) addition
	Matrix<T> operator+(const Matrix<T>& other) const {
		// Matrices need to be compatible; 
		//		Let A and B be matrices, 
		//		We assert that shape(A) == shape(B),
		//			Where shape(*) returns a 2-tuple (pair) of the matrix's dimension (row x col)
		if (rows == other.rows && cols == other.cols) {
			Matrix<T> resulting_matrix(rows, cols);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					resulting_matrix.elements[i][j] = this->elements[i][j] + other.elements[i][j];
				}
			}
			return resulting_matrix;
		}
		else {
			throw std::invalid_argument("Matrices are not compatible for addition."); // Changed from std::cout to exception
		}
	}
	// Need to overload operator- for elementwise (matrix) substraction
	Matrix<T> operator-(const Matrix<T>& other) const {
		// Matrices need to be compatible; 
		//		Let A and B be matrices, 
		//		We assert that shape(A) == shape(B),
		//			Where shape(*) returns a 2-tuple (pair) of the matrix's dimension (row x col)
		if (rows == other.rows && cols == other.cols) {
			Matrix<T> resulting_matrix(rows, cols);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					resulting_matrix.elements[i][j] = this->elements[i][j] - other.elements[i][j];
				}
			}
			return resulting_matrix;
		}
		else {
			throw std::invalid_argument("Matrices are not compatible for addition."); // Changed from std::cout to exception
		}
	}
	// Need to overload operator* for matrix multiplication
	Matrix<T> operator* (const Matrix<T>& other) const {
		// Matrices need to be compatible;
		//      Let A and B be matrices, we need [i x j] * [j x k] 
		//      We need cols(A) == rows(B),
		//          Where cols(*) and rows(*) return an integer 

		if (cols != other.rows) {
			throw std::invalid_argument("Matrices are not compatible for multiplication.");
		}

		Matrix<T> resulting_matrix(rows, other.cols);
		// Perform matrix multiplication
		for (int i = 0; i < rows; i++) {
			for (int k = 0; k < other.cols; k++) {
				T sum{ };
				for (int j = 0; j < cols; j++) {
					sum += this->elements[i][j] * other.elements[j][k];
				}
				resulting_matrix.elements[i][k] = sum;
			}
		}
		return resulting_matrix;
	}

	// Need to overload operator== 
	bool operator== (const Matrix<T>& other) const {
		// Matrices need to be compatible;
		//      Let A and B be matrices, we need [i x j] == [i x j],
		//      Further, we need A_ij == B_ij for all i and j in A and B, 
		//			If all is satisified, A == B is true

		// Check dimensions
		if ((rows != other.rows)||(cols != other.cols)) {
			return false;
		}

		// Check elements
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (this->elements[i][j] != other.elements[i][j])
					return false;
			}
		}
		return true;
	}

	// Need to overload operator!= 
	bool operator!= (const Matrix<T>& other) const {
		// Matrices need to be compatible;
		//      Let A and B be matrices, we need [i x j] == [i x j],
		//      Further, we need A_ij == B_ij for all i and j in A and B, 
		//			If all is satisified, A == B is true, implies A != B is false

		// Check dimensions
		if ((rows != other.rows) || (cols != other.cols)) {
			return true;
		}

		// Check elements
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (this->elements[i][j] != other.elements[i][j])
					return true;
			}
		}
		return false;
	}

	// Copy constructor for copying matrices
	Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols), elements(nullptr) {
		if (rows > 0 && cols > 0) {
			elements = new T * [rows];
			for (int i = 0; i < rows; i++) {
				elements[i] = new T[cols];
				for (int j = 0; j < cols; j++) {
					elements[i][j] = other.elements[i][j];
				}
			}
		}
	}

	// Overloaded copy assignment operator
	Matrix& operator=(const Matrix& other) {
		if (this == &other) {
			return *this;
		}

		deallocateMemory();

		rows = other.rows;
		cols = other.cols;

		if (rows > 0 && cols > 0) {
			elements = new T * [rows];
			for (int i = 0; i < rows; i++) {
				elements[i] = new T[cols];
				for (int j = 0; j < cols; j++) {
					elements[i][j] = other.elements[i][j];
				}
			}
		}
		else {
			elements = nullptr;
		}

		return *this;
	}
};

// Overload for operator<<, outside of class for ostream left operand
template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
	if (matrix.rows == 0 || matrix.cols == 0) {
		os << "Empty Matrix\n";
		return os;
	}
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.cols; j++) {
			os << std::setw(10) << matrix.elements[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}


int main()
{
	int a_row, a_col;
	int b_row, b_col;
	std::cout << " Keep in mind that matrix A will be multiplied with matrix B (A*B).";
	std::cout << "\n Enter a 2-tuple (pair) for the dimensions of matrix A (row x column) separated by a space: ";
	std::cin >> a_row >> a_col;
	std::cout << "\n Enter a 2-tuple (pair) for the dimensions of matrix B (row x column) separated by a space: ";
	std::cin >> b_row >> b_col;

	int scalar;
	std::cout << "\n Enter a scalar for scaling matrix A: ";
	std::cin >> scalar;
	
	
	Matrix<int> matrixA(a_row, a_col);
	std::cout << "Enter elements for Matrix<int> A:\n"; // Prompt for matrix A
	matrixA.assignElements();
	Matrix<int> matrixB(b_row, b_col);
	std::cout << "Enter elements for Matrix<int> B:\n"; // Prompt for matrix B
	matrixB.assignElements();
	std::cout << "Matrix A:\n" << matrixA;
	std::cout << "Matrix B:\n" << matrixB;

	try {
		std::cout << "Transpose of A:\n" << (matrixA.transpose());

		std::cout << "Scaled A (by " << scalar << "): \n" << (matrixA.scalarMultiply(scalar));

		std::cout << "Sum of A and B:\n" << (matrixA + matrixB);

		std::cout << "Difference of A and B:\n" << (matrixA - matrixB);

		std::cout << "Product of A and B:\n" << (matrixA * matrixB);

		std::cout << "A and B are equal: " << (((matrixA == matrixB) && !(matrixA != matrixB)) ? "yes" : "no") << '\n';
	}
	catch (const std::invalid_argument& e) { // Added exception handling
		std::cerr << e.what() << '\n';
	}

	return 0;
}