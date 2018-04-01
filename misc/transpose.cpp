#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Matrix;

void printMatrix(Matrix& matrix, int rows, int columns);
void transpose(Matrix& init, Matrix& fin, int rows, int columns);

int main() {
	Matrix initMatrix;
	Matrix finalMatrix;
	int rows, columns;

	cout << "How many rows? ";
	cin >> rows;

	cout << "How many columns? ";
	cin >> columns;

	for (int i = 0; i < rows * columns; i++) {
		int num;

		cout << "What number? ";
		cin >> num;

		initMatrix.push_back(num);
	}

	cout << "Initial Matrix: " << endl;
	printMatrix(initMatrix, rows, columns);
	
	transpose(initMatrix, finalMatrix, columns, rows);

	cout << "Final Matrix: " << endl;
	printMatrix(finalMatrix, columns, rows);

	return 0;
}


void transpose(Matrix& init, Matrix& fin, int rows, int columns) {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			fin.push_back(init.at(j * columns + i));
		}
	}	
}


void printMatrix(Matrix& matrix, int rows, int columns) {
	int idx = 0;

	for (int val : matrix) {
		cout << "[" << matrix.at(idx) << "]";
		idx++;	
		if (idx % columns == 0) 
			cout << "\n";	
	}	
}	


