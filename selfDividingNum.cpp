#include <iostream>		// Use cout and others
#include <vector>		// Vector use
#include <string>		// for string use 
#include <fstream>		// For i/o input


using namespace std;

class Solution {
public: 
	vector<int> selfDividingNumbers(int left, int right) {
		// Create an empty int vector 
		vector<int> selfDividingNums;

		// Loop through the lower to upper bounds
		for (int i = 0; i <= right-left; i++) {
			// Get the current number in the left->right range
			int num = left + i;

			// Check if the number is divisible
			if (canSelfDivide(num)) {
				// if so, add it to the vector
				selfDividingNums.push_back(num);
			}
		}

		// return all self dividing numbers
		return selfDividingNums;
	}

	bool canSelfDivide(int num) {

		// Create a copy of the number, this will be the one we will manipulate
		int copy = num;

		// loop through the number's digits
		while (copy > 0) {
			// get the digit at the end of the number
			int endDigit = copy % 10;
			// cout << num << " digit: " << endDigit << endl;

			// Check if the digit is 0 or cannot divide the number
			if (endDigit == 0 || (num % endDigit != 0)) {
				return false;
			}

			// get rid of the last digit in the number, (e.g. 128 -> 12)
			copy = copy / 10;
		}
		return true;
	}
};

int main() {
	// Create an instance of the Solution class
	Solution *sol = new Solution();

	// Get input from user
	int left, right;
	cout << "Enter lower bound of array: ";
	cin >> left;

	cout << "Enter upper bound of array: ";
	cin >> right;

	// Get the array
	vector<int> ans = sol->selfDividingNumbers(left, right);

	// Print out solution
	cout << "Solution: " << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans.at(i) << ' ';
	}

	return 0;
}				