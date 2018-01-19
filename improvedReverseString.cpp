#include <iostream>		// use cout and others
#include <string> 		// used for strings


using namespace std;

class Solution {
public:
	string reverseString(string s) {
		
		// Create left and right side of the string
		int l = 0, r = s.size() - 1;

		while(l < r) {
			char temp = s[l];
			s[l++] = s[r];
			s[r--] = temp;
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

	//cout << "You entered: " << strToReverse << endl;

	string reversedStr = solution->reverseString(strToReverse);
	cout << "Reversed: " << reversedStr << endl;

	return 0;
}

