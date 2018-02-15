/*
 * Yufang Lin
 * My solution to leetCode problem called, "Hamming Distance":
 * https://leetcode.com/problems/hamming-distance/description/
 *
*/
#include <iostream>		// For cout, cin, etc.

using namespace std;


class Solution {
public:
	int hammingDistance(int x, int y) {
		/*
		 * Calculate the hamming distance between two numbers
		 * type	x:	int
		 * type y:	int
		 * rtype :	int
		 *
		*/

		// Create a variable to store the distance
		int dist = 0;

		// get the number with all bits that differs from x and y
		int diff = x^y;

		// Loop through the difference until it reaches 0
		while(diff) {
			// increment the distance
			dist++;
			diff &= diff - 1;
		}

		// return the distance
		return dist;
	}
};

int main() {
	// Print out title
	cout << "\n--------------- Hamming Distance ---------------\n";
	// Create an instance of the Solution class
	Solution *sol = new Solution();

	// Ask user for x input
	cout << "Enter x: ";
	int x;
	cin >> x;

	// Ask user for y input
	cout << "\nEnter y: ";
	int y;
	cin >> y;

	// Get the hamming distance
	int ans = sol->hammingDistance(x, y);

	// Output the hamming distance
	cout << "Hamming Distance: " << ans << endl;

	return 0;
}

