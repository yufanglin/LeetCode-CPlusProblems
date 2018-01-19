#include <iostream>		// use cout and others
#include <string> 		// used for strings

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		/*
		 * Reverses the words in a sentence
		 *
		 * type s:	string
		 * rtype :	string
		 *
		*/

		// Create a string vector to hold the words in the string
		string word = "";

		// Create a new string to return
		string reversedWordsInStr = "";

		cout << s << endl;
		// loop through string
		for(int i = 0; i < s.size(); i++) {
			cout << s[i] << " ";
			// Check if the character isn't an empty space
			if(s[i] != ' ') {
				// add character to word
				word += s[i];

				cout << word << endl;
			}
			// Check if the character is a space or if at the end of the sentence and if a word has already been found
			if((i == s.size()-1 || s[i] == ' ') && word != "") {
				cout << "reversing word..." << endl;
				// Reverse word
				reversedWordsInStr += reverseString(word);

				// Check if this is the last word, if so, don't add a space
				if(i < s.size()-1) {
					reversedWordsInStr += ' ';
				}

				cout << reversedWordsInStr << endl;

				// reset the word
				word = "";
			}
		}

		return reversedWordsInStr;

	}

	string reverseString(string s) {
		/*
		 * Reverses the given string
		 *
		 * type	s:	string
		 * rtype :	string
		 *
		*/

		// Get the upmost left and right indexes of the string
		int l = 0, r = s.size() - 1;

		// Loop through the string until left/right index meet at the middle
		while(l < r) {
			// Create temp to hold left index's value
			char temp = s[l];
			// replace left index's value with right index's and then increment left index
			s[l++] = s[r];
			// replace right index's value with left index's and then decrement right index
			s[r--] = temp;
		}

		return s;
	}
};

int main() {
	// Create an instance of the solution class
	Solution *sol = new Solution();

	// Save the string to reverse the words
	string usrInput;
	// Ask for user input and retrieve user's input
	cout << "Input: ";
	getline(cin, usrInput);

	cout << usrInput << endl;

	// Get the solution
	string ans = sol->reverseWords(usrInput);

	// print out solution
	cout << "Output: " << ans << endl;

	return 0;
}