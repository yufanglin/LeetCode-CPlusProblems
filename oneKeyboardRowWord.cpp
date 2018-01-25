#include <iostream>		// For cout, cin, etc
#include <string>		// For strings
#include <vector>		// For vectors
#include <algorithm>	// for find()

using namespace std;

class Solution {
public:

	char row1[10] {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
	char row2[9] {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
	char row3[7] {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

	vector<string> findWords(vector<string>& words) {
		/*
		 * Find the words in a vector that can be created 
		 * using only one keyboard row.
		 *
		 * type	words 	: vector<string>
		 * rtype		: vector<string>
		*/

		// Create an empty array to add words to
		vector<string> oneRowWords;

		// loop through the words
		for(int i = 0; i < words.size(); i++) {
			// Check if the word can be found on one row
			if(oneRow(words[i])) {
				// add word vector
				oneRowWords.push_back(words[i]);
				continue;
			}
		}

		// return the vector
		return oneRowWords;
	}

	bool oneRow(string word) {
		/*
		 * Check if the word can be created on one keyboard
		 * 
		 * type	word 	: string
		 * rtype		: bool
		*/

		int rowIndex = 0; // 0=hasn't determine row, 1=row 1, 2=row 2, 3=row 3

		// loop through the word
		for(int i=0; i < word.length(); i++) {

			// Check word's char is in the first row
			if (find(row1, row1+10, tolower(word[i])) != row1+10) {
				// if the row index has yet to be set
				if(rowIndex == 0) {
					// set row index to 1 and continue to next char
					rowIndex = 1;
					continue;
				}
				// if the row index is already set to 1
				else if(rowIndex == 1) {
					// just continue to next char
					continue;
				}
				// otherwise, the word had a previous char found on another row
				else {
					// this word takes more than one row to make, return false
					return false;
				}
			} // First Row check


			// Check word's char is in the second row
			else if (find(row2, row2+9, tolower(word[i])) != row2+9) {
				// if the row index has yet to be set
				if(rowIndex == 0) {
					// set row index to 2 and continue to next char
					rowIndex = 2;
					continue;
				}
				// if the row index is already set to 2
				else if(rowIndex == 2) {
					// just continue to next char
					continue;
				}
				// otherwise, the word had a previous char found on another row
				else {
					return false;
				}
			} // Middle Row Check


			// Check word's char is in the third row
			else if (find(row3, row3+7, tolower(word[i])) != row3+7) {
				// if the row index has yet to be set
				if(rowIndex == 0) {
					// Set row index to 3 and continue to the next char
					rowIndex = 3;
					continue;
				}
				// if the row index is already set to 3
				else if(rowIndex == 3) {
					// just continue to next char
					continue;
				}
				// otherwise, the word had a previous char found on another row
				else {
					return false;
				}
			} // Last Row Check

		} // End of looping through the word

		// If program gets to here, then the word was made using one row
		return true;
	}
};


int main() {

	// Create an instance of the Solution class
	Solution *sol = new Solution();

	// Create an example array to test algorithm with
	vector<string> testVector = {"Hello", "Alaska", "Dad", "Peace"};

	// Get the words that can be made with one keyboard row
	vector<string> ans = sol->findWords(testVector);

	for(int i = 0; i < ans.size(); i++) {
		cout << "One Keyboard Row: " << ans[i] << endl;
	}

	return 0;
}