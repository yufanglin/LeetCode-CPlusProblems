#include <iostream>		// use cout and others
#include <string> 		// used for strings


using namespace std;

class Solution {
public:
	string reverseString(string s) {
		
		// Get half of the length of the string 
		int halfLength = s.length() / 2;
		
		// Loop through the characters in string and swap them
		for(int i = 0; i < halfLength; i++) {
			char temp = s[s.length() - 1 - i];
			cout << temp << endl;
			s[s.length() - 1 - i] = s[i];
			s[i] = temp;
		}
		return s;
	}
};

int main() {
	// Create a instance of the solution class
	Solution *solution = new Solution();

	// Get user input
	string strToReverse;
	cout << "Enter a string to reverse: ";
	cin >> strToReverse;

	cout << "You entered: " << strToReverse << endl;

	string reversedStr = solution->reverseString(strToReverse);
	cout << "Reversed: " << reversedStr << endl;

	return 0;
}

