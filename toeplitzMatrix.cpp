/*
 * Toeplitz Matriz
 * Yufang Lin
 *
 * My Solution to leetCode problem called, "Toeplitz Matrix":
 * https://leetcode.com/problems/toeplitz-matrix/description/
*/

#include <iostream>		// for cout/cin
#include <vector>		// for vectors

using namespace std;

class Solution
{
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		/*
		 * Checks if every top-left to bottom-right diagonal of a matrix 
		 * has the same int value
		 * type matrix 		:	int[,]
		 * rtype			: bool
		*/

		// loop through each vector (row) in the 2-dimensional vector
		for(int row = 0; row < matrix.size(); row++) {
			
			// loop through each int value (col) in the inner vectors (row)
			for (int col = 0; col < matrix.front().size(); col++) {

				// skip the first row/col since they ar ethe lower bounds
				if(row > 0 && col > 0) {
					// Check if each element is NOT  equal to the prev row/col element
					if (matrix[row-1][col-1] != matrix[row][col]) { 
						return false; 
					}

					// else continue to the next element
					continue;
				}
				// else continue to the next row
				continue;
			}
		}

		// If reach this point, then matrix is a Toeplitz matrix
		return true;
	}
	
};

int main() {
	// create reference to the solution class
	Solution* sol = new Solution();

	// -- First example: IS Toeplitz Matrix
	vector<vector<int>> firstMatrix;

	vector<int> fMFirstRow;
	vector<int> fMSecondRow;
	vector<int> fMThirdRow;

	fMFirstRow.push_back(1);
	fMFirstRow.push_back(2);
	fMFirstRow.push_back(3);
	fMFirstRow.push_back(4);

	fMSecondRow.push_back(5);
	fMSecondRow.push_back(1);
	fMSecondRow.push_back(2);
	fMSecondRow.push_back(3);

	fMThirdRow.push_back(9);
	fMThirdRow.push_back(5);
	fMThirdRow.push_back(1);
	fMThirdRow.push_back(2);

	firstMatrix.push_back(fMFirstRow);
	firstMatrix.push_back(fMSecondRow);
	firstMatrix.push_back(fMThirdRow);


	// -- Second example: NOT Toeplitz Matrix
	vector<vector<int>> secondtMatrix;

	vector<int> sMFirstRow;
	vector<int> sMSecondRow;

	sMFirstRow.push_back(1);
	sMFirstRow.push_back(2);

	sMSecondRow.push_back(2);
	sMSecondRow.push_back(2);

	secondtMatrix.push_back(sMFirstRow);
	secondtMatrix.push_back(sMSecondRow);


	// test solution
	bool firstMatrixSol = sol->isToeplitzMatrix(firstMatrix);
	bool secondMatrixSol = sol->isToeplitzMatrix(secondtMatrix);

	// print results
	if (firstMatrixSol) {
		cout << "First Matrix is Toeplitz" << endl;
	}
	else {
		cout << "First Matrix is NOT Toeplitz" << endl;
	}

	if (secondMatrixSol) {
		cout << "Second Matrix is Toeplitz" << endl;
	}
	else {
		cout << "Second Matrix is NOT Toeplitz" << endl;
	}

	return 0;
}

