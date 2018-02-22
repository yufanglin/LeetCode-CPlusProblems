/*
 * Number Complement
 * Yufang Lin
 *
 * My Solution to leetCode problem called ,"Number Complement":
 * https://leetcode.com/problems/number-complement/description/
*/

#import <iostream> 	// For cout, cin, etc
#import <string>	// For strings

using namespace std;

class Solution {
public:
	int findComplement(int num) {
		/*
		 * Find the binary complement of a num and return
		 * the complement as an integer
		 *
		 * type	num 	: int
		 * rtype		: int
		*/

		// Create a tracker, set it to the number
		int tracker = num;

		// Create a number whose binary version will eventually only have one leftmost '1'
		int leftMostOne = 0;

		// Loop until tracker reaches 0, because 0's binary version has no '1' left to remove
		while(tracker) {
			// Set leftMostOne to tracker, eventually the binary version will look something like: 100
			leftMostOne = tracker;

			// Remove the rightmost '1'
			tracker &= tracker - 1;
		}

		// Shift leftMostOne to the left, e.g.: 100 -> 1000
		// remove 1, so leftMostOne's binary will be made out of 1's: 1000 - 0001 = 111
		// Find the difference between the number and leftMostOne, that difference is the complement:
		//		Ex: 5 ^ 4 = (101) ^ (111) = 010
		return num ^ ((leftMostOne << 1) - 1);

	}
};

int main() {
	// Create an instance to the solution class
	Solution *sol = new Solution();

	// Get user input
	cout << "Input a number: ";
	int num;
	cin >> num;

	// Get the complement
	int complement = sol->findComplement(num);

	cout << "Complement: " << complement << endl;

	return 0;
}