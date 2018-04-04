/*
 * Number of Lines To Write String
 * Yufang Lin
 *
 * My Solution to leetCode problem called, "Number of Lines To Write String":
 * https://leetcode.com/problems/number-of-lines-to-write-string/description/
*/

#import <iostream>		// for cout/cin
#import <vector>		// for vectors
#import <string>		// for strings

using namespace std;


class Solution
{
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		/*
		 * Each line as 100 units of space. Each character may be
		 * many units wide. This function determines how many lines
		 * it will take to write out a string of characters
		 * type widths 		: vector<int>
		 * type S 			: String
		 * rtype   			: vector<int>
		 *
		*/

		// Create an empty vector for number of lines and extra units 
		vector<int> result;

		// create a storage for the number of lines and width counter
		int linesCounter = 1;
		int lineWidth = 0;

		for(char& c: S) {
			// find the number of units this character takes up by getting
			// the index, which can be found by subtracting the unicode of the
			// character with the unicode of 'a'
			int unit = widths.at(c - 'a');
			// add the units with the current line's width
			lineWidth += unit;

			// Check if the current line's width is over the max 100
			if (lineWidth > 100) {
				// if so, then increment the line count
				linesCounter++;
				// move the current char's width to the new line's width
				lineWidth = unit;
			}
		}

		// add the line count and leftover width to the result
		result.push_back(linesCounter);
		result.push_back(lineWidth);

		// return the results
		return result;
	}
	
};

int main() {

	// create an instance of the solution class
	Solution* sol = new Solution();

	// create examples 
	vector<int> widths1(26, 10);
	string S1 = "abcdefghijklmnopqrstuvwxyz";

	vector<int> widths2;
	widths2.push_back(4);
	widths2.insert(widths2.end(), 25, 10);
	string S2 = "bbbcccdddaaa";

	
	// find the line count for both examples
	vector<int> ans1 = sol->numberOfLines(widths1, S1);
	vector<int> ans2 = sol->numberOfLines(widths2, S2);


	cout << "Ex1 Number of Lines: " << ans1.at(0) << endl;
	cout << "Ex1 Number of Units: " << ans1.at(1) << endl;


	cout << "\nEx2 Number of Lines: " << ans2.at(0) << endl;
	cout << "Ex2 Number of Units: " << ans2.at(1) << endl;	

	return 0;
}
