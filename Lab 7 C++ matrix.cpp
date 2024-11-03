#include <iostream> //allow io
#include <fstream> //allow file io
#include <string> //allow strings

using namespace std;

//set matrix size to 4
const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
	int data[SIZE][SIZE] = { 0 };  // 2D array for matrix data (using int for simplicity)

public:
	// 1. Read values from stdin into a matrix
	void readFromStdin();

	// 2. Display a matrix
	void display() const;




	// 3. Add two matrices (operator overloading for +)
	Matrix operator+(const Matrix& other) {
		Matrix sum; //create a matrix to be returned
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				//cycle through every item, add the 2 items togteher, and add them to the new matrix
				sum.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return sum; //return new matrix
	}

	// 4. Multiply two matrices (operator overloading for *)
	Matrix operator*(const Matrix& other) const {
		Matrix product;//create a matrix to be returned
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				//set the new value in the new matrix to be 0
				product.data[i][j] = 0;
				for (int k = 0; k < SIZE; k++) {
					//calculate dot product
					product.data[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		return product; //return new matrix
	}

	// 5. Compute the sum of matrix diagonal elements
	int sumOfDiagonals() const;

	// 6. Swap matrix rows
	void swapRows(int row1, int row2);
};

//method to red in a matrix
void Matrix::readFromStdin() {
	//define string to store the filename
	string filename;
	//read in the file name
	cin >> filename;
	//open a file with the name of the filename
	ifstream file(filename);

	//check for invalid file name
	if (!file) {
		cout << "\nInvalid File Name.\n ";
		return;
	}

	//cycle through each row and column until you get all of the numbers
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE;j++) {
			file >> data[i][j]; //store number
		}
	}

	file.close(); //close the file when finished

}

//method to display the matrix
void Matrix::display() const {
	//cycle through every item in the matrix
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << data[i][j] << " "; //print each row
		}
		cout << "\n"; //make a new row
	}
}

//method to sum all of the diagonals
int Matrix::sumOfDiagonals()  const {
	int total = 0; //varaible to store totla
	//first diagonal
	for (int i = 0; i < SIZE; i++) {
		total += data[i][i];
	}
	//seconds diagonal
	for (int i = 0; i < SIZE; i++) {
		total += data[i][SIZE - 1 - i];
	}
	return total; //return total
}

void Matrix::swapRows(int row1, int row2) {
	//check for valid row input
	if (row1 >= SIZE || row1 < 0 || row2 >= SIZE || row2 < 0) {
		cout << "\nInvalid Row Size.\n ";
		return;
	}
	//array to temporarily store the values
	int temp[SIZE];
	//set temp to row 1
	for (int i = 0; i < SIZE; i++) {
		temp[i] = data[row1][i];
	}
	//set row 1 to row 2
	for (int i = 0; i < SIZE; i++) {
		data[row1][i] = data[row2][i];
	}
	//set row 2 to roe 1 (temp)
	for (int i = 0; i < SIZE; i++) {
		data[row2][i] = temp[i];
	}
}

int main() {
	//code provided by instructor
	// Example usage:
	Matrix mat1;

	cout << "Enter file name for Matrix 1 (including .txt):" << endl;
	mat1.readFromStdin();
	cout << "\nMatrix 1:\n" << endl;
	mat1.display();

	Matrix mat2;
	cout << "\nEnter file name for Matrix 2 (including .txt):" << endl;
	mat2.readFromStdin();
	cout << "\nMatrix 2:\n" << endl;
	mat2.display();

	Matrix sum = mat1 + mat2;
	cout << "\nSum of matrices:" << endl;
	sum.display();

	Matrix product = mat1 * mat2;
	cout << "\nProduct of matrices:" << endl;
	product.display();

	cout << "\nSum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

	mat1.swapRows(0, 2);
	cout << "\nMatrix 1 after swapping rows:" << endl;
	mat1.display();

	return 0;
}
